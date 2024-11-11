#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100005], u, v, cnt;
long long dfs(long long x) {
  if (x == 0) return 0;
  m = x + v;
  long long y = m - 1;
  for (int i = 0; i < cnt; ++i) {
    while (x < m % a[i] && i < cnt - 1) a[i] = a[--cnt];
    if (m - m % a[i] >= v) y = min(y, m - m % a[i]);
  }
  return dfs(y - v) + 1;
}
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    cnt = 1;
    for (int i = 1; i < n; ++i)
      if (a[i] != a[i - 1]) a[cnt++] = a[i];
    cin >> u >> v;
    cout << dfs(u - v) << endl;
  }
}
