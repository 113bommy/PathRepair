#include <bits/stdc++.h>
using namespace std;
int n, b, d, sum, a, s;
int main() {
  cin >> n >> b >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a <= b) {
      s += a;
    }
    if (s > d) {
      sum++;
      s = 0;
    }
  }
  cout << sum << endl;
  return 0;
}
