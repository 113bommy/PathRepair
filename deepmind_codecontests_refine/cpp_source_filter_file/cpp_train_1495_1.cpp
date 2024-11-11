#include <bits/stdc++.h>
using namespace std;
const int N = (int)(1e6 + 2);
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int max(long long int a, long long int b) { return a > b ? a : b; }
long long int min(long long int a, long long int b) { return a < b ? a : b; }
void solve();
int main() {
  clock_t start = clock();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  fprintf(stderr, "time=%.3lfsec\n", 0.000001 * (clock() - start));
}
long long int fun(long long int a) {
  if (a < 10) return a;
  int l = a % 10;
  long long int ans = 9 + (a - 10) / 10;
  while (a >= 10) a = a / 10;
  if (l >= a) ans++;
  return ans;
}
void solve() {
  long long int l, r;
  cin >> l >> r;
  cout << fun(r - 1) - fun(l - 1) << '\n';
}
