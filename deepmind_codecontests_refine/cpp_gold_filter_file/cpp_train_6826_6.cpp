#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x = -100000;
  string t;
  while (n--) {
    string s;
    int y, z, a, b, c, d, e, m;
    cin >> s >> y >> z >> a >> b >> c >> d >> e;
    m = a + b + c + d + e;
    m += y * 100;
    m -= z * 50;
    if (m > x) {
      x = m;
      t = s;
    }
  }
  cout << t;
}
