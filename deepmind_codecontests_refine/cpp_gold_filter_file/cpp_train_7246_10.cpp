#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const long long INF = 4e18L + 1;
const int IINF = 2e9 + 1;
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << '=' << h << endl;
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
int ile[8];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int ostatni, progres;
  for (int i = 0; i < n; i++) {
    int akt;
    cin >> akt;
    int ap = akt - ostatni;
    if (i == 0) {
      ostatni = akt;
    } else if (i == 1) {
      ostatni = akt;
      progres = ap;
    } else if (i >= 2 && progres != ap)
      progres = 0;
    ostatni = akt;
  }
  cout << ostatni + progres;
  return 0;
}
