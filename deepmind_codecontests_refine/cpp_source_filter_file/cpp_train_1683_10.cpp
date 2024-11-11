#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " |";
  __f(comma + 1, args...);
}
void solve() {
  long long k;
  cin >> k;
  long long tot = 0, f = 9;
  long long nd = 1;
  while (tot + f * nd < k) {
    tot += f;
    f *= 10;
    nd++;
  }
  k -= tot;
  f /= 9;
  long long n = f - 1 + ceil(k / (double)nd);
  k %= nd;
  if (!k) k = nd;
  k = (nd - k);
  while (k--) {
    n /= 10;
  }
  cout << n % 10 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1, tc = 1;
  while (T--) {
    solve();
  }
  return 0;
}
