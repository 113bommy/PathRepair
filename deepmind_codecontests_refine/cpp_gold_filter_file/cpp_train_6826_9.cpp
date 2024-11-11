#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d1, d2, d3, d4, d5, e, f, n, sum, sums = -1000000;
  string s, ans;
  cin >> n;
  for (int f = 0; f < (n); f++) {
    cin >> s >> b >> c >> d1 >> d2 >> d3 >> d4 >> d5;
    sum = b * 100 - c * 50 + d1 + d2 + d3 + d4 + d5;
    if (sum > sums) {
      ans = s;
      sums = sum;
    };
  }
  cout << ans;
}
