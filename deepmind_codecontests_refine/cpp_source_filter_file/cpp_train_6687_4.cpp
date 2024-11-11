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
template <typename T, typename U>
istream& operator>>(istream& in, pair<T, U>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
inline vector<T> READ(int n) {
  vector<T> vec(n);
  for (int i = 0; i < int(n); i++) cin >> vec[i];
  return vec;
}
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;
signed long long int solve(int d, signed long long int mod) {
  int log = log2(d);
  signed long long int diff = 1;
  for (int i = 0; i < int(log); i++) {
    diff = diff * ((1 << i) + 1) % mod;
  }
  signed long long int rem = d - (1 << log) + 1;
  signed long long int num = (diff - 1 + rem * diff) % mod;
  cout << num << endl;
  return num;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    signed long long int d, mod;
    cin >> d >> mod;
    solve(d, mod);
  }
}
