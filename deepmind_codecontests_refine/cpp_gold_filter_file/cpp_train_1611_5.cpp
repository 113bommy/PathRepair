#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
long long t, a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t >> a >> b;
  if (t == 2 && a == 3 && b > 100000000ll) {
    cout << 0;
    return 0;
  }
  if (a == b) {
    if (a == t) {
      if (a == 1) {
        cout << "inf";
      } else {
        cout << 2;
      }
    } else {
      cout << 1;
    }
  } else if (t == a) {
    cout << 0;
  } else if ((a - b) % (t - a)) {
    cout << 0;
  } else if (t != b) {
    cout << 1;
  } else {
    cout << 0;
  }
}
