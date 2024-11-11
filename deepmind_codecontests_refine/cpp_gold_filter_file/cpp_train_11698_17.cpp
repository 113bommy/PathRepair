#include <bits/stdc++.h>
using namespace std;
void solve(istream &in, ostream &out) {
  int n;
  in >> n;
  int totalA = 0, totalB = 0, succeededA = 0, succeededB = 0;
  for (int i = 0; i < n; ++i) {
    int t, x, y;
    in >> t >> x >> y;
    if (t == 1) {
      succeededA += x;
      totalA += 10;
    } else {
      succeededB += x;
      totalB += 10;
    }
  }
  out << (succeededA >= totalA / 2 ? "LIVE" : "DEAD") << endl;
  out << (succeededB >= totalB / 2 ? "LIVE" : "DEAD") << endl;
}
int main() {
  solve(cin, cout);
  return 0;
}
