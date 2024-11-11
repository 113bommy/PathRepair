#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;
char s[500005];
long long fx[5][500005];
int pt[5];
long long mnh[500005], mnl[500005];
int n, h, w, posx, posy;
int lim[5];
int hcnt, lcnt;
long long ans = 0;
void count() {
  sort(mnh + 1, mnh + h + 1);
  sort(mnl + 1, mnl + w + 1);
  hcnt = lcnt = 1;
  while (hcnt <= h && lcnt <= w) {
    if (mnh[hcnt] <= mnl[lcnt])
      ans = (ans + mnh[hcnt++] % mod * (1 + w - lcnt)) % mod;
    else
      ans = (ans + mnl[lcnt++] % mod * (1 + h - hcnt)) % mod;
  }
}
void update(int tim) {
  int pos[5] = {0, posy, -posy, -posx, posx};
  for (int i = 1; i <= 4; i++) {
    if (pt[i] + 1 == pos[i]) fx[i][++pt[i]] = tim;
  }
}
void calc(int side) {
  int pos[5] = {0, posy, -posy, -posx, posx};
  int d = pos[side];
  if (d <= 0) return;
  while (pt[side] < lim[side]) {
    for (int i = pt[side] - d + 1; i <= pt[side]; i++) {
      if (i + d > lim[side]) break;
      fx[side][i + d] = fx[side][i] + n;
    }
    pt[side] = min(lim[side], pt[side] + d);
  }
}
int main() {
  scanf("%d%d%d", &n, &h, &w);
  memset(fx, 0x3f, sizeof(fx));
  lim[1] = lim[2] = w;
  lim[3] = lim[4] = h;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'U')
      posy++;
    else if (s[i] == 'L')
      posx--;
    else if (s[i] == 'D')
      posy--;
    else if (s[i] == 'R')
      posx++;
    update(i);
  }
  for (int i = 1; i <= 4; i++) calc(i);
  bool nev[2];
  nev[0] = nev[1] = false;
  for (int i = 1; i <= h; i++)
    if ((mnh[i] = min(fx[1][i], fx[2][h + 1 - i])) == INF) nev[0] = true;
  for (int i = 1; i <= w; i++)
    if ((mnl[i] = min(fx[3][i], fx[4][w + 1 - i])) == INF) nev[1] = true;
  if (nev[0] && nev[1]) return puts("-1"), 0;
  count();
  cout << ans << endl;
  return 0;
}
