#include <bits/stdc++.h>
using namespace std;
long long n, t;
int main() {
  long long i, s, min_ = 10001000, flag = 0;
  cin >> n >> t;
  for (i = 1; i <= n; i++) {
    long long si, di;
    cin >> si >> di;
    if (si < t) {
      si += (t - si) / di * di;
    }
    if (si < t) si += di;
    if (flag == 0) {
      if (si == t) {
        flag = 1;
        min_ = si;
        s = i;
      } else if (si > t && si < min_) {
        min_ = si;
        s = i;
      }
    }
  }
  cout << s;
  return 0;
}
