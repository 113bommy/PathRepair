#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmax(T &x, T y) {
  x = x > y ? x : y;
}
template <class T>
void chmin(T &x, T y) {
  x = x < y ? x : y;
}
const int inf = 1000000000;
const int mod = 1000000007;
int main() {
  int n, ans = inf + inf;
  cin >> n;
  for (int j = 30; ~j; j--) {
    if (n >= 1 << j) {
      int rem = n - 1 << j;
      if (rem % 2) continue;
      ans = min(ans, rem / 2);
    }
  }
  cout << ans << endl;
  return 0;
}
