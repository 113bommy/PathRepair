#include <bits/stdc++.h>
using namespace std;
long long const max1 = 20;
long long const mod = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    string s;
    cin >> s;
    string h1 = s.substr(0, 2), m1 = s.substr(3, 2);
    float h = stof(h1);
    float m = stof(m1);
    float ha = 0, ma = 0;
    if (h == 12) {
      ha = 0;
    } else if (h > 12) {
      h = h - 12;
    }
    ha = 30 * h;
    ma = m * 6;
    ha += 0.5 * m;
    cout << fixed << setprecision(10) << ha << " " << ma;
  }
}
