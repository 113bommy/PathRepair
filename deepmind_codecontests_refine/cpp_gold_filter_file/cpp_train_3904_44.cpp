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
long long n, m;
long long calc(long long x, long long y) {
  return min(min(x, n + 1 - x), min(y, m + 1 - y));
}
signed main() {
  ios_base::sync_with_stdio(0);
  long long TESTS = 1;
  while (TESTS--) {
    cin >> n >> m;
    long long k;
    cin >> k;
    long long mn = (long long)1e15;
    for (long long i = 0; i < k; i++) {
      long long x, y;
      cin >> x >> y;
      mn = min(mn, calc(x, y));
    }
    if (mn <= 5)
      cout << "YES";
    else
      cout << "NO";
  }
}
