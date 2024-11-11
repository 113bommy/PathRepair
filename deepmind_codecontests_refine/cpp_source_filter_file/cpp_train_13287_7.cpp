#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
template <typename T>
inline void amin(T& x, T y) {
  if (x > y) x = y;
}
template <typename T>
inline void amax(T& x, T y) {
  if (x < y) x = y;
}
void prepro() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(17);
  int n, a, b, ans = 1;
  cin >> n >> a >> b;
  for (auto x = (1); x <= (100); x++)
    if (a / x + b / x >= n) {
      amax(ans, x);
    }
  cout << ans;
  ;
  return 0;
}
