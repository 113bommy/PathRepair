#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int da, db, ha, hb, h, hmax = -1, dfirst, dlast, hfirst, hlast;
  cin >> da >> ha;
  dfirst = da;
  hfirst = ha;
  hmax = ha;
  if (m == 1) {
    dlast = da;
    hlast = ha;
  }
  m--;
  bool ans = 1;
  while (m--) {
    cin >> db >> hb;
    if (m == 0) {
      dlast = db;
      hlast = hb;
    }
    if (hb < max(0, ha - (db - da)) || hb > ha + (db - da)) ans = 0;
    h = (db - da + ha + hb) / 2;
    if (h > hmax) hmax = h;
    da = db;
    ha = hb;
  }
  hmax = max(dfirst - 1 + hfirst, max(n - dlast + hlast, hmax));
  if (ans)
    cout << hmax;
  else
    cout << "IMPOSSIBLE";
}
