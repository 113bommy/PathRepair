#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 100;
const int L = 2e5 + 100;
const int INF = 0x3f3f3f3f;
int n, m;
int a[N], c[N], g[N];
int lowbit(int x) { return x & -x; }
int add(int x) {
  for (int i = x; i < N; i += lowbit(i)) c[i] += 1;
  return 0;
}
int sum(int x) {
  int res = 0;
  for (int i = x; i; i -= lowbit(i)) res += c[i];
  return res;
}
long long solve(int x) {
  memset(c, 0, sizeof(c));
  long long ans = 0;
  add(L);
  for (int i = 1; i <= n; i++) {
    if (a[i] <= x)
      g[i] = g[i - 1] + 1;
    else
      g[i] = g[i - 1] - 1;
    ans += sum(g[i] + L);
    add(g[i] + L);
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  cout << solve(m) - solve(m - 1) << endl;
}
