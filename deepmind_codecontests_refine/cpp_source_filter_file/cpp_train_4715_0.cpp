#include <bits/stdc++.h>
using namespace std;
int T, h, v;
int l[1010], p[1010];
bitset<1010 * 1010> dpl[1010], dpp[1010];
int as[1010], af[1010], bs[1010], bf[1010];
int nowaf, nowas, nowbf, nowbs;
bool dp() {
  dpl[0][0] = 1;
  dpp[0][0] = 1;
  int suml = 0, sump = 0;
  for (int i = 1; i <= h; i++) {
    dpl[i] = (dpl[i - 1] << l[i]) | dpl[i - 1];
    suml += l[i];
    dpp[i] = (dpp[i - 1] << p[i]) | dpp[i - 1];
    sump += p[i];
  }
  if ((suml & 1) || (sump & 1)) return 0;
  if ((!dpl[h][suml >> 1]) || (!dpp[v][sump >> 1])) return 0;
  suml >>= 1, sump >>= 1;
  for (int i = h; i >= 1; i--) {
    if (dpl[i - 1][suml])
      af[++nowaf] = l[i];
    else
      suml -= l[i], as[++nowas] = l[i];
  }
  for (int i = v; i >= 1; i--) {
    if (dpp[i - 1][sump])
      bf[++nowbf] = p[i];
    else
      sump -= p[i], bs[++nowbs] = p[i];
  }
  return 1;
}
bool cmp(int a, int b) { return a > b; }
int ansa[1010], ansb[1010];
int main() {
  cin >> T;
  while (T--) {
    nowaf = nowas = nowbf = nowbs = 0;
    cin >> h;
    for (int i = 1; i <= h; i++) cin >> l[i];
    cin >> v;
    for (int j = 1; j <= v; j++) cin >> p[j];
    if (h != v) {
      cout << "No" << endl;
      continue;
    }
    if (!dp()) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
    if (nowaf > nowas) swap(af, as), swap(nowaf, nowas);
    if (nowbf > nowbs) swap(bf, bs), swap(nowbf, nowbs);
    sort(af + 1, af + 1 + nowaf, cmp);
    sort(as + 1, as + 1 + nowas, cmp);
    sort(bf + 1, bf + 1 + nowbf), sort(bs + 1, bs + 1 + nowbs);
    int nowx = 0, nowy = 0;
    int nowpp = 0;
    for (int i = 1; i <= nowaf; i++) ansa[++nowpp] = af[i];
    for (int i = 1; i <= nowas; i++) ansa[++nowpp] = -as[i];
    nowpp = 0;
    for (int i = 1; i <= nowbf; i++) ansb[++nowpp] = bf[i];
    for (int i = 1; i <= nowbs; i++) ansb[++nowpp] = -bs[i];
    for (int i = 1; i <= h; i++) {
      nowx += ansa[i];
      cout << nowx << " " << nowy << endl;
      nowy += ansb[i];
      cout << nowx << " " << nowy << endl;
    }
  }
}
