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
  int n;
  cin >> n;
  vector<int> a = readVector<int>(n);
  signed long long int candies = accumulate((a).begin(), (a).end(), 0LL);
  if (candies == 1) EXIT(-1);
  vector<signed long long int> primes;
  for (int p = int(2); p <= int(1e6 + 5); p++) {
    if (candies % p == 0) {
      primes.push_back(p);
      while (candies % p == 0) candies /= p;
    }
  }
  if (candies > 1) primes.push_back(candies);
  signed long long int ans = 1e18;
  for (auto pc : primes) {
    signed long long int sum = 0;
    signed long long int moves = 0;
    for (int i = 0; i < int(n); i++) {
      sum += a[i];
      signed long long int down = sum % pc;
      signed long long int up = pc - down;
      moves += abs(min(down, up));
    }
    ans |= MIN(moves);
  }
  cout << ans << endl;
  return 0;
}
