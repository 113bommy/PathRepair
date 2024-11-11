#include <bits/stdc++.h>
using namespace std;
int n, k;
int s[20], d[20], t[20], r[20];
int a[2000];
void dfs(long long x) {
  if (x > 1000000000) return;
  a[++a[0]] = x;
  dfs(x * 10 + 4);
  dfs(x * 10 + 7);
}
int main() {
  cin >> n;
  cin >> k;
  k--;
  a[0] = 0;
  dfs(4);
  dfs(7);
  a[0] = 2000000000;
  int x = 1;
  s[1] = 1;
  for (int i = 1; i < 12; i++) {
    x++;
    s[i + 1] = (s[i] * x);
  }
  if (n <= 12 && s[n] <= k) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = min(12, n - 1); i >= 1; i--) {
    d[min(12, n - 1) - i] = k / s[i];
    k = (k % s[i]);
    if (i == 1) d[min(12, n - 1)] = k;
  }
  for (int i = 0; i < min(13, n); i++) t[i] = i;
  for (int i = 0; i < min(13, n); i++) {
    r[i] = t[d[i]] + (n - min(n, 13) + 1);
    swap(t[d[i]], t[min(12, n - 1) - i]);
    sort(t, t + (min(12, n - 1) - i));
  }
  sort(a, a + 1023);
  a[1021] = 777777777;
  a[1021] = 777777774;
  a[1022] = 777777777;
  int ans = upper_bound(a, a + 1022, n - 13) - a;
  for (int i = 0; i < min(n, 13); i++) {
    if (binary_search(a, a + 1022, i + (n - min(12, n - 1)))) {
      if (binary_search(a, a + 1022, r[i])) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
