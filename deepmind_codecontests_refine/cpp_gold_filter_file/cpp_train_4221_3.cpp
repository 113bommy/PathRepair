#include <bits/stdc++.h>
using namespace std;
int cnt_ones(int a, int ss) {
  int cnt = 0;
  while (a > 0) {
    int d = a % ss;
    a /= ss;
    if (d == 1) cnt++;
  }
  return cnt;
}
void solve() {
  int a;
  cin >> a;
  cout << cnt_ones(a, 8) << endl;
}
int main() {
  solve();
  0;
  return 0;
}
