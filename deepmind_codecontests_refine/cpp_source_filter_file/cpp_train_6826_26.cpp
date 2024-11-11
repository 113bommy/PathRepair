#include <bits/stdc++.h>
using namespace std;
int n, rs, a, b, c, d, e, p, q;
vector<string> s;
int main() {
  int i, j, mm = 0;
  string tmp;
  string rec;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> tmp;
    cin >> p >> q >> a >> b >> c >> d >> e;
    rs = p * 100 - q * 50 + a + b + c + d + e;
    if (rs > mm) {
      rec = tmp;
      mm = rs;
    }
  }
  cout << rec;
}
