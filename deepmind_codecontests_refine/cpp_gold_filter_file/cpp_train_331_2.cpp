#include <bits/stdc++.h>
using namespace std;
bool RELAXED = false;
template <int, typename T>
struct MINMAX {
  T val;
  MINMAX(T val) : val(val) {}
};
template <typename T>
MINMAX<1, T> MAX(T val) {
  return MINMAX<1, T>(val);
};
template <typename T>
MINMAX<2, T> MIN(T val) {
  return MINMAX<2, T>(val);
};
template <typename T, typename U>
inline T& operator|=(T& lhs, MINMAX<1, U> rhs) {
  return lhs = (rhs.val > lhs ? (RELAXED = true, rhs.val)
                              : (RELAXED = false, lhs));
}
template <typename T, typename U>
inline T& operator|=(T& lhs, MINMAX<2, U> rhs) {
  return lhs = (rhs.val < lhs ? (RELAXED = true, rhs.val)
                              : (RELAXED = false, lhs));
}
template <typename T>
inline vector<T> readVector(int n) {
  vector<T> vec(n);
  for (int i = 0; i < int(n); i++) cin >> vec[i];
  return vec;
}
template <typename T>
void EXIT(T answer) {
  cout << answer << endl;
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  signed long long int x;
  cin >> x;
  vector<signed long long int> primes;
  for (int p = int(2); p <= int(1e6 + 5); p++) {
    if (x % p) continue;
    signed long long int pp = p;
    while (x % (pp * p) == 0) pp *= p;
    x /= pp;
    primes.push_back(pp);
  }
  if (x > 1) primes.push_back(x);
  signed long long int best = 1e18;
  pair<signed long long int, signed long long int> ans;
  for (int i = 0; i < int(1 << 20); i++) {
    signed long long int a = 1, b = 1;
    for (int j = 0; j < int(primes.size()); j++)
      if ((1 << j) & i)
        a *= primes[j];
      else
        b *= primes[j];
    best |= MIN(max(a, b));
    if (RELAXED) ans = {a, b};
  }
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
