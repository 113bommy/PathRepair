#include <bits/stdc++.h>
using namespace std;
void Run() {
  int i, j, k, m, n, a, b, d, t, tc, mn, nb, kmn, aa, bb, lg, lw, lc, som, mx,
      alkjhlkh;
  int res, N;
  long long lsom;
  double dres, dsom;
  string s, st, sres, S;
  char c;
  bool fg, fgpossible;
  vector<long long> vt, vcost, vres;
  do {
    vt.clear();
    vcost.clear();
    vres.clear();
    res = 0;
    dres = 0;
    sres = "";
    cin >> n;
    vt.push_back(0);
    vcost.push_back(0);
    vres.push_back(0);
    for (i = 0; i < n; i++) {
      cin >> a;
      vt.push_back(a);
      vcost.push_back(0);
      vres.push_back(0);
    }
    for (i = 1; i <= n; i++) {
      t = vt[i];
      vcost[i] = vcost[i - 1] + 20;
      j = lower_bound(vt.begin(), vt.begin() + i - 1, t - 90 + 1) - vt.begin();
      if (j >= 1) j--;
      vcost[i] = min(vcost[i], vcost[j] + 50);
      j = lower_bound(vt.begin(), vt.begin() + i - 1, t - 1440 + 1) -
          vt.begin();
      if (j >= 1) j--;
      vcost[i] = min(vcost[i], vcost[j] + 120);
    }
    for (i = 1; i <= n; i++) cout << vcost[i] - vcost[i - 1] << "\n";
    break;
  } while (true);
}
int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  unsigned int i;
  Run();
  return 0;
}
