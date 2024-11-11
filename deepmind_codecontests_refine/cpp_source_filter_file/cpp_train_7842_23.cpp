#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int n, t, k, b, l, m;
void solve() {
  cin >> k >> b >> n >> t;
  if (k == 1) {
    long long int need = 1 + b * n - t;
    if (need <= 0) {
      cout << 0;
      return;
    }
    cout << need / b + (need % b != 0);
    return;
  }
  long long int ans = 0, temp = 1;
  while (temp * (k - 1 + b) <= t * (k - 1) * b) {
    ans++;
    temp *= k;
  }
  ans--;
  if (ans >= n)
    cout << 0;
  else
    cout << n - ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
