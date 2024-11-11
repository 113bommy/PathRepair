#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    cout << (n - 1) / 2 << endl;
  }
  return 0;
}
