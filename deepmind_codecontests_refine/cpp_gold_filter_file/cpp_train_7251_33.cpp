#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " = " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " = " << arg1 << " ";
  __f(comma + 1, args...);
}
long long int ceil(long long int a, long long int b) { return (a + b - 1) / b; }
void solve() {
  long long int n, s, temp, ans = 0;
  cin >> n >> s;
  vector<long long int> v;
  vector<pair<long long int, long long int>> x;
  for (long long int i = 0; i < (long long int)n; i++) {
    long long int a, b;
    cin >> a >> b;
    x.push_back({a, b});
    v.push_back(a * 60 + b);
  }
  if (v[0] > s) {
    cout << "0 0" << '\n';
    return;
  }
  for (long long int i = 0; i < (long long int)v.size() - 1; i++) {
    if (v[i + 1] - v[i] > 2 * s + 1) {
      ans = v[i] + 1 + s;
      cout << ans / 60 << " " << ans % 60 << '\n';
      return;
    }
  }
  ans = v[v.size() - 1] + 1 + s;
  cout << ans / 60 << " " << ans % 60 << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Test = 1;
  while (Test--) {
    solve();
  }
  return 0;
}
