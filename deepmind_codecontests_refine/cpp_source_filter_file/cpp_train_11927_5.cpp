#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXH = 2000;
const int MAXW = 2000;
const int MAXN = 2000;
const int MAXLEN = 2000;
const int MAXSLEN = MAXN * MAXLEN;
const int MAXQ = 1000000;
const int MAXQASK = 2000;
const int SZ = 17;
const int MAXBH = (MAXH + SZ - 1) / SZ;
const int MAXBW = (MAXW + SZ - 1) / SZ;
int h, w, n;
int len[MAXN];
int slen[MAXN + 1];
int x[MAXSLEN], y[MAXSLEN], z[MAXSLEN];
int sb[MAXN + 1];
int bx[MAXSLEN], by[MAXSLEN];
long long bval[MAXSLEN];
int bkey[MAXBH][MAXBW], bid[MAXBH][MAXBW];
int gidx[MAXH][MAXW];
int gz[MAXH][MAXW];
bool on[MAXN];
long long bgz[MAXBH][MAXBW];
int nq;
char command[10];
void toggle(int idx) {
  on[idx] = !on[idx];
  if (!on[idx])
    for (int i = (sb[idx]); i < (sb[idx + 1]); ++i)
      bgz[bx[i]][by[i]] -= bval[i];
  if (on[idx])
    for (int i = (sb[idx]); i < (sb[idx + 1]); ++i)
      bgz[bx[i]][by[i]] += bval[i];
}
long long calc(int lx, int ly, int hx, int hy) {
  long long ret = 0;
  while (lx < hx && lx % SZ != 0) {
    for (int y = (ly); y < (hy); ++y) {
      int idx = gidx[lx][y];
      if (idx != -1 && on[idx]) ret += gz[lx][y];
    }
    ++lx;
  }
  while (lx < hx && hx % SZ != 0) {
    --hx;
    for (int y = (ly); y < (hy); ++y) {
      int idx = gidx[hx][y];
      if (idx != -1 && on[idx]) ret += gz[hx][y];
    }
  }
  while (ly < hy && ly % SZ != 0) {
    for (int x = (lx); x < (hx); ++x) {
      int idx = gidx[x][ly];
      if (idx != -1 && on[idx]) ret += gz[x][ly];
    }
    ++ly;
  }
  while (ly < hy && hy % SZ != 0) {
    --hy;
    for (int x = (lx); x < (hx); ++x) {
      int idx = gidx[x][hy];
      if (idx != -1 && on[idx]) ret += gz[x][hy];
    }
  }
  if (lx == hx || ly == hx) return ret;
  lx /= SZ, hx /= SZ, ly /= SZ, hy /= SZ;
  for (int x = (lx); x < (hx); ++x)
    for (int y = (ly); y < (hy); ++y) ret += bgz[x][y];
  return ret;
}
void run() {
  scanf("%d%d%d", &h, &w, &n);
  slen[0] = 0;
  for (int i = (0); i < (n); ++i) {
    scanf("%d", &len[i]);
    slen[i + 1] = slen[i] + len[i];
    for (int j = (0); j < (len[i]); ++j)
      scanf("%d%d%d", &x[slen[i] + j], &y[slen[i] + j], &z[slen[i] + j]),
          --x[slen[i] + j], --y[slen[i] + j];
  }
  memset(gidx, -1, sizeof(gidx));
  memset(gz, 0, sizeof(gz));
  memset(bgz, 0, sizeof(bgz));
  memset(bkey, -1, sizeof(bkey));
  sb[0] = 0;
  for (int i = (0); i < (n); ++i) {
    sb[i + 1] = sb[i];
    on[i] = true;
    for (int j = (slen[i]); j < (slen[i + 1]); ++j) {
      int cbx = x[j] / SZ, cby = y[j] / SZ;
      gidx[x[j]][y[j]] = i, gz[x[j]][y[j]] = z[j], bgz[cbx][cby] += z[j];
      if (bkey[cbx][cby] != i) {
        bkey[cbx][cby] = i;
        int id = bid[cbx][cby] = sb[i + 1]++;
        bx[id] = cbx, by[id] = cby, bval[id] = 0;
      }
      bval[bid[cbx][cby]] += z[j];
    }
  }
  scanf("%d", &nq);
  for (int qi = (0); qi < (nq); ++qi) {
    scanf("%s", command);
    if (strcmp(command, "SWITCH") == 0) {
      int idx;
      scanf("%d", &idx);
      --idx;
      toggle(idx);
    }
    if (strcmp(command, "ASK") == 0) {
      int lx, ly, hx, hy;
      scanf("%d%d%d%d", &lx, &ly, &hx, &hy);
      --lx, --ly;
      long long ret = calc(lx, ly, hx, hy);
      printf("%lld\n", ret);
    }
  }
}
int main() {
  run();
  return 0;
}
