#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename T>
T amod(T a) {
  if (a < 0) a = -a;
  return a;
}
void solve() {
  long long int c1, c2, d1, d2, r1, r2;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
  for (long long int i = 1; i < 20; i++) {
    for (long long int j = 1; j < 20; j++) {
      for (long long int k = 1; k < 20; k++) {
        for (long long int l = 1; l < 20; l++) {
          if (i == j || i == k || i == l || j == k || j == l || k == l) {
            continue;
          }
          if (r1 == (i + j) && r2 == (k + l) && c1 == (i + k) &&
              c2 == (j + l) && d1 == (i + l) && d2 == (j + k)) {
            cout << i << " " << j << "\n" << k << " " << l;
            return;
          }
        }
      }
    }
  }
  cout << "-1";
}
int main() {
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
