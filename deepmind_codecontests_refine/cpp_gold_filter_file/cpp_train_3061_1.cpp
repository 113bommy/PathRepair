#include <bits/stdc++.h>
using namespace std;
int n, m;
int e[50][50];
int re[50][50];
int efrom[1225];
int eto[1225];
int ecntv[1225];
int efirstv[1225];
int elastv[1225];
int eself[1225];
int nv;
int vval[100000];
int vnext[100000];
int vprev[100000];
int qh, qt;
int q[100];
int p[101];
int ntrans;
int firsttrans[100];
int nexttrans[122500];
int translen[122500];
int transto[122500];
const int MOD = 1000000007;
int cntways[102][100][100];
void run(int casenr) {
  memset(e, -1, sizeof(e));
  nv = 0;
  ntrans = 0;
  memset(firsttrans, -1, sizeof(firsttrans));
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (m); ++i) {
    scanf("%d%d%d", &efrom[i], &eto[i], &ecntv[i]);
    efrom[i]--;
    eto[i]--;
    e[efrom[i]][eto[i]] = i;
    re[eto[i]][efrom[i]] = i;
    efirstv[i] = elastv[i] = -1;
    for (int j = (0); j < (ecntv[i]); ++j) {
      scanf("%d", &vval[nv]);
      --vval[nv];
      if (j == 0) {
        efirstv[i] = elastv[i] = nv;
        vnext[nv] = vprev[nv] = -1;
      } else {
        vprev[nv] = elastv[i];
        vnext[nv] = -1;
        vnext[vprev[nv]] = nv;
        elastv[i] = nv;
      }
      ++nv;
    }
  }
  for (int i = (0); i < (m); ++i) {
    eself[i] = -1;
    for (int j = efirstv[i]; j != -1; j = vnext[j])
      if (vval[j] == efrom[i] && vnext[j] != -1 && vval[vnext[j]] == eto[i]) {
        eself[i] = j;
        break;
      }
  }
  for (int i = (0); i < (m); ++i)
    if (eself[i] != -1) {
      bool ok = true;
      int plen = 2;
      int at;
      qh = qt = 0;
      for (int j = vprev[eself[i]]; j != -1; j = vprev[j])
        if (plen < 2 * n + 1) {
          q[qh++] = vval[j];
          ++plen;
        } else
          ok = false;
      at = efrom[i];
      while (qt < qh) {
        int to = q[qt++];
        if (e[to][at] == -1 || eself[e[to][at]] != -1) {
          ok = false;
          break;
        }
        for (int j = elastv[e[to][at]]; j != -1; j = vprev[j])
          if (plen < 2 * n + 1) {
            q[qh++] = vval[j];
            ++plen;
          } else
            ok = false;
        at = to;
      }
      if (!ok) continue;
      int pstart = at;
      plen = 0;
      for (int j = qh - 1; j >= 0; --j) p[plen++] = q[j];
      p[plen++] = efrom[i];
      p[plen++] = eto[i];
      qh = qt = 0;
      for (int j = vnext[vnext[eself[i]]]; j != -1; j = vnext[j])
        if (plen < 2 * n + 1) {
          q[qh++] = vval[j];
          ++plen;
        } else
          ok = false;
      at = eto[i];
      while (qt < qh) {
        int to = q[qt++];
        if (e[at][to] == -1) {
          ok = false;
          break;
        }
        for (int j = efirstv[e[at][to]]; j != -1; j = vnext[j])
          if (plen < 2 * n + 1) {
            q[qh++] = vval[j];
            ++plen;
          } else
            ok = false;
        at = to;
      }
      int pend = at;
      if (!ok) continue;
      plen -= qh;
      for (int j = 0; j < qh; ++j) p[plen++] = q[j];
      nexttrans[ntrans] = firsttrans[n + pstart];
      firsttrans[n + pstart] = ntrans;
      translen[ntrans] = plen;
      transto[ntrans] = pend;
      ++ntrans;
    }
  for (int i = (0); i < (m); ++i)
    if (eself[i] == -1 && elastv[i] != -1 && vval[elastv[i]] == efrom[i]) {
      bool ok = true;
      int plen = 1;
      int at;
      qh = qt = 0;
      for (int j = vprev[elastv[i]]; j != -1; j = vprev[j])
        if (plen < 2 * n + 1) {
          q[qh++] = vval[j];
          ++plen;
        } else
          ok = false;
      at = efrom[i];
      while (qt < qh) {
        int to = q[qt++];
        if (e[to][at] == -1 || eself[e[to][at]] != -1) {
          ok = false;
          break;
        }
        for (int j = elastv[e[to][at]]; j != -1; j = vprev[j])
          if (plen < 2 * n + 1) {
            q[qh++] = vval[j];
            ++plen;
          } else
            ok = false;
        at = to;
      }
      if (!ok) continue;
      int pstart = at, pend = eto[i];
      nexttrans[ntrans] = firsttrans[n + pstart];
      firsttrans[n + pstart] = ntrans;
      translen[ntrans] = plen;
      transto[ntrans] = n + pend;
      ++ntrans;
    }
  for (int i = (0); i < (m); ++i)
    if (efirstv[i] != -1 && vval[efirstv[i]] == eto[i]) {
      bool ok = true;
      int plen = 1;
      int at;
      qh = qt = 0;
      for (int j = vnext[efirstv[i]]; j != -1; j = vnext[j])
        if (plen < 2 * n + 1) {
          q[qh++] = vval[j];
          ++plen;
        } else
          ok = false;
      at = eto[i];
      while (qt < qh) {
        int to = q[qt++];
        if (e[at][to] == -1) {
          ok = false;
          break;
        }
        for (int j = efirstv[e[at][to]]; j != -1; j = vnext[j])
          if (plen < 2 * n + 1) {
            q[qh++] = vval[j];
            ++plen;
          } else
            ok = false;
        at = to;
      }
      if (!ok) continue;
      int pstart = efrom[i], pend = at;
      nexttrans[ntrans] = firsttrans[pstart];
      firsttrans[pstart] = ntrans;
      translen[ntrans] = plen;
      transto[ntrans] = pend;
      ++ntrans;
    }
  for (int i = (0); i < (m); ++i)
    if (ecntv[i] == 0) {
      int pstart = efrom[i], pend = eto[i], plen = 0;
      nexttrans[ntrans] = firsttrans[pstart];
      firsttrans[pstart] = ntrans;
      translen[ntrans] = plen;
      transto[ntrans] = n + pend;
      ++ntrans;
    }
  memset(cntways, 0, sizeof(cntways));
  for (int j = (0); j < (n); ++j) cntways[0][n + j][n + j] = 1;
  for (int i = (0); i < (2 * n + 1); ++i)
    for (int j = (0); j < (2 * n); ++j)
      for (int k = (0); k < (2 * n); ++k)
        if (cntways[i][j][k] != 0)
          for (int x = firsttrans[k]; x != -1; x = nexttrans[x])
            if (i + translen[x] <= 2 * n + 1) {
              cntways[i + translen[x]][j][transto[x]] += cntways[i][j][k];
              if (cntways[i + translen[x]][j][transto[x]] >= MOD)
                cntways[i + translen[x]][j][transto[x]] -= MOD;
            }
  for (int i = (2); i <= (2 * n + 1); ++i) {
    int cur = 0;
    for (int j = (0); j < (n); ++j)
      for (int k = (0); k < (n); ++k) {
        cur += cntways[i][n + j][k];
        if (cur >= MOD) cur -= MOD;
      }
    printf("%d\n", cur);
  }
}
int main() {
  run(1);
  return 0;
}
