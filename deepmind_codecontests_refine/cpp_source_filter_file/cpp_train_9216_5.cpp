#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d, sum, diff, diff1, diff2, diff3;
int main() {
  cin >> n >> a >> b >> c >> d;
  for (int i = 1; i <= n; i++) {
    diff = i + a + b;
    diff1 = diff - a - c;
    diff2 = diff - b - d;
    diff3 = diff - c - d;
    if (diff1 >= 1 && diff1 <= n && diff2 >= 1 && diff2 <= n && diff3 >= 1 &&
        diff3 <= n)
      sum++;
  }
  cout << sum * n;
}
