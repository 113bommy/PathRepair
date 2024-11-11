#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9 + 10;
const double eps = 1e-4;
const double mod = 1e9 + 7;
int main() {
  int n, s, d, now = 0;
  cin >> n;
  while (n--) {
    cin >> s >> d;
    if (now < s)
      now = s;
    else {
      int k = (now - s) / d;
      if (k * d + s > now)
        now = k * d + s;
      else
        now = k * d + s + d;
    }
  }
  cout << now << endl;
}
