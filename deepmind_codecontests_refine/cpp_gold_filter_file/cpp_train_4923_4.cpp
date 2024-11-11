#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    long long int zero = 0, one = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '0')
        zero++;
      else
        one++;
    }
    if (c0 == c1) {
      cout << zero * c0 + one * c1 << endl;
    } else if (c0 + h < c1) {
      cout << zero * (c0) + one * (c0 + h) << endl;
    } else if (c1 + h <= c0) {
      cout << one * c1 + zero * (c1 + h) << endl;
    } else {
      cout << zero * c0 + one * c1 << endl;
    }
  }
}
