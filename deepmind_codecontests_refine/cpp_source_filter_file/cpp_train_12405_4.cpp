#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795l;
template <typename T>
inline auto sqr(T x) -> decltype(x * x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 200100;
long long fact[N];
const long long mod = 998244353ll;
int st[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(20);
  fact[0] = 1;
  for (int i = int(1); i < int(N); ++i) {
    (fact[i] = fact[i - 1] * i) %= mod;
  }
  int n;
  cin >> n;
  for (int i = int(0); i < int(n - 1); ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ++st[a];
    ++st[b];
  }
  long long ans = n;
  for (int i = int(0); i < int(n); ++i) {
    (ans *= fact[i]) %= mod;
  }
  cout << ans << endl;
  return 0;
}
