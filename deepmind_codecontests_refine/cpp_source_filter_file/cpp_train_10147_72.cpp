#include <bits/stdc++.h>
template <class T>
const T& max(const T& a, const T& b) {
  return a > b ? a : b;
}
template <class T>
const T& min(const T& a, const T& b) {
  return a < b ? a : b;
}
using namespace std;
int main() {
  uint64_t a(0), b(0), c(0), n(0), m(0), k(0);
  cin >> n;
  if (n % 2 == 1) {
    cout << "black" << endl;
    return 0;
  }
  if (n % 2) {
    cout << "white" << endl << "1 2" << endl;
    return 0;
  }
  return 0;
}
