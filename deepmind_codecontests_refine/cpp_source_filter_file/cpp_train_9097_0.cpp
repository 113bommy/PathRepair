#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void checkMax(T& a, const T& b) {
  if (a < b) a = b;
}
template <typename T>
inline void checkMin(T& a, const T& b) {
  if (a > b) a = b;
}
long long calc(long long n) {
  if (n % 3 == 0) {
    return n / 3;
  } else {
    return n / 3 + 1;
  }
}
int main() {
  long long n;
  cin >> n;
  cout << calc(n) << endl;
  return 0;
}
