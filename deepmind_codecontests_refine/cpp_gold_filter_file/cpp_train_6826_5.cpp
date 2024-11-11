#include <bits/stdc++.h>
using namespace std;
void fast() { std::ios_base::sync_with_stdio(0); }
int main() {
  int t, suc, unsuc, a, b, c, d, e, mx = -100000;
  string x, first;
  cin >> t;
  while (t--) {
    cin >> x >> suc >> unsuc >> a >> b >> c >> d >> e;
    int score = suc * 100 - unsuc * 50 + a + b + c + d + e;
    if (score >= mx) mx = score, first = x;
  }
  cout << first << endl;
}
