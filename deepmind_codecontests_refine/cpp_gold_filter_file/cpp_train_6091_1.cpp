#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100005];
void add(long long *c, int x, long long v) {
  for (; x <= n; x += x & -x) c[x] += v;
}
long long sum(long long *c, int x) {
  long long res = 0;
  for (; x >= 1; x -= x & -x) res += c[x];
  return res;
}
void input() {
  cin >> n >> k;
  k++;
  for (int i = 1; i <= n; ++i) cin >> a[i];
}
long long f[12];
long long c[12][100005];
void solve() {
  long long ans = 0;
  f[0] = 1;
  add(c[0], 0 + 1, 1);
  for (int i = 1; i <= n; ++i) {
    memset(f, 0, sizeof(f));
    for (int j = 1; j <= k; ++j) {
      f[j] += sum(c[j - 1], a[i]);
      add(c[j], a[i] + 1, f[j]);
    }
    ans += f[k];
  }
  cout << ans << endl;
}
int main() {
  input();
  solve();
  return 0;
}
