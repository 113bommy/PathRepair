#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 12;
int f[N], r[N];
int pw(int a, int b) {
  if (b == 0) return 1;
  int c = pw(a, b / 2);
  c = c * 1LL * c % mod;
  if (b % 2 == 1) c = c * 1LL * a % mod;
  return c;
}
void init() {
  f[0] = r[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = f[i - 1] * 1LL * i % mod;
  }
  r[N - 1] = pw(f[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; --i) {
    r[i] = (r[i + 1]) * (1LL) * (i + 1) % mod;
  }
}
int C(int n, int k) { return f[n] * 1LL * r[k] % mod * r[n - k] % mod; }
int main() {
  init();
  int n;
  cin >> n;
  int ans = 1, cur_count, cal, total_ele = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> cur_count;
    cal = C(cur_count + total_ele - 1, cur_count - 1);
    ans = ans * 1LL * cal % mod;
    total_ele += cur_count;
  }
  cout << ans;
}
