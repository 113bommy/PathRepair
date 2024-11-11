#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXSONG = 400000;
const int MAXQ = 400000;
const int MAXNODE = MAXSONG + 1;
const int MAXQLEN = 400000;
const int MAXLG = 19;
int nsong;
int par[MAXNODE];
char parc[MAXNODE];
int nq;
int qidx[MAXQ], qoff[MAXQ], qlen[MAXQ];
char qs[MAXQLEN + 1];
int qans[MAXQ];
int sa[MAXNODE];
int val[MAXNODE];
int pos[MAXNODE];
int up[MAXNODE][MAXLG + 1];
int cnt[MAXNODE + 1];
int tmp[MAXNODE];
int ql[MAXQ], qr[MAXQ];
vector<int> qat[MAXNODE];
vector<int> ch[MAXNODE];
int bit[MAXNODE + 1];
int bget(int idx) {
  ++idx;
  int ret = 0;
  while (idx > 0) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}
void bmod(int idx, int by) {
  ++idx;
  while (idx <= nsong + 1) {
    bit[idx] += by;
    idx += idx & -idx;
  }
}
void print() {
  for (int i = (0); i <= (nsong); ++i) {
    int at = sa[i];
    printf("%2d (%2d):", at, val[at]);
    while (at != -1) {
      printf("%c", parc[at]);
      at = par[at];
    }
    puts("");
  }
}
int cmp(int at, char *s, int len) {
  for (int i = (0); i < (len); ++i) {
    char a = parc[at], b = s[i];
    if (a != b) return a < b ? -1 : +1;
    at = par[at];
  }
  return 0;
}
void dfs(int at) {
  bmod(pos[at], +1);
  for (int _ = (0); _ < (((int)(qat[at]).size())); ++_) {
    int id = qat[at][_], l = ql[id], r = qr[id];
    qans[id] = bget(r - 1) - bget(l - 1);
  }
  for (int i = (0); i < (((int)(ch[at]).size())); ++i) {
    int to = ch[at][i];
    dfs(to);
  }
  bmod(pos[at], -1);
}
void solve() {
  for (int i = (0); i <= (nsong); ++i) up[i][0] = par[i] == -1 ? i : par[i];
  for (int k = (0); k < (MAXLG); ++k)
    for (int i = (0); i <= (nsong); ++i) up[i][k + 1] = up[up[i][k]][k];
  int alph = 256;
  for (int i = (0); i < (alph); ++i) cnt[i] = 0;
  for (int i = (0); i <= (nsong); ++i) ++cnt[(int)parc[i]];
  for (int i = alph - 1; i >= 0; --i) cnt[i + 1] = cnt[i], cnt[i] = 0;
  for (int i = (0); i < (alph); ++i) cnt[i + 1] += cnt[i];
  for (int i = (0); i <= (nsong); ++i) sa[cnt[(int)parc[i]]++] = i;
  alph = 0;
  for (int i = (0); i <= (nsong); ++i)
    if (i != 0 && parc[sa[i]] == parc[sa[i - 1]])
      val[sa[i]] = alph - 1;
    else
      val[sa[i]] = alph++;
  for (int k = (0); k <= (MAXLG); ++k) {
    for (int i = (0); i < (alph); ++i) cnt[i] = 0;
    for (int i = (0); i <= (nsong); ++i) ++cnt[val[up[i][k]]];
    for (int i = alph - 1; i >= 0; --i) cnt[i + 1] = cnt[i], cnt[i] = 0;
    for (int i = (0); i < (alph); ++i) cnt[i + 1] += cnt[i];
    for (int i = (0); i <= (nsong); ++i) tmp[cnt[val[up[i][k]]]++] = i;
    for (int i = (0); i < (alph); ++i) cnt[i] = 0;
    for (int i = (0); i <= (nsong); ++i) ++cnt[val[i]];
    for (int i = alph - 1; i >= 0; --i) cnt[i + 1] = cnt[i], cnt[i] = 0;
    for (int i = (0); i < (alph); ++i) cnt[i + 1] += cnt[i];
    for (int i = (0); i <= (nsong); ++i) sa[cnt[val[tmp[i]]]++] = tmp[i];
    alph = 0;
    for (int i = (0); i <= (nsong); ++i)
      if (i != 0 && val[sa[i]] == val[sa[i - 1]] &&
          val[up[sa[i]][k]] == val[up[sa[i - 1]][k]])
        tmp[sa[i]] = alph - 1;
      else
        tmp[sa[i]] = alph++;
    for (int i = (0); i <= (nsong); ++i) val[i] = tmp[i];
  }
  for (int i = (0); i <= (nsong); ++i) pos[sa[i]] = i;
  for (int i = (0); i <= (nsong); ++i) qat[i].clear();
  for (int i = (0); i < (nq); ++i) {
    reverse(qs + qoff[i], qs + qoff[i] + qlen[i]);
    int l, r;
    {
      int lo = -1, hi = nsong + 1;
      while (lo + 1 < hi) {
        int mi = lo + (hi - lo) / 2;
        if (cmp(sa[mi], qs + qoff[i], qlen[i]) >= 0)
          hi = mi;
        else
          lo = mi;
      }
      l = hi;
    }
    {
      int lo = -1, hi = nsong + 1;
      while (lo + 1 < hi) {
        int mi = lo + (hi - lo) / 2;
        if (cmp(sa[mi], qs + qoff[i], qlen[i]) > 0)
          hi = mi;
        else
          lo = mi;
      }
      r = hi;
    }
    reverse(qs + qoff[i], qs + qoff[i] + qlen[i]);
    ql[i] = l, qr[i] = r;
    qat[qidx[i]].push_back(i);
  }
  for (int i = (0); i <= (nsong); ++i) ch[i].clear();
  for (int i = (0); i <= (nsong); ++i)
    if (par[i] != -1) ch[par[i]].push_back(i);
  for (int i = (0); i <= (nsong + 1); ++i) bit[i] = 0;
  dfs(0);
}
void run() {
  scanf("%d", &nsong);
  par[0] = -1, parc[0] = '-';
  for (int i = (1); i <= (nsong); ++i) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1)
      par[i] = 0;
    else
      scanf("%d", &par[i]);
    scanf(" %c", &parc[i]);
  }
  scanf("%d", &nq);
  qoff[0] = 0;
  for (int i = (0); i < (nq); ++i) {
    scanf("%d%s", &qidx[i], qs + qoff[i]);
    qlen[i] = strlen(qs + qoff[i]);
    qoff[i + 1] = qoff[i] + qlen[i];
  }
  solve();
  for (int i = (0); i < (nq); ++i) printf("%d\n", qans[i]);
}
int qansstupid[MAXQ];
void solvestupid() {
  for (int i = (0); i < (nq); ++i) {
    vector<char> tmp;
    for (int at = qidx[i]; parc[at] != '-'; at = par[at])
      tmp.push_back(parc[at]);
    reverse(tmp.begin(), tmp.end());
    qansstupid[i] = 0;
    for (int j = (0); j <= (((int)(tmp).size()) - qlen[i]); ++j) {
      bool ok = true;
      for (int k = (0); k < (qlen[i]); ++k)
        if (tmp[j + k] != qs[qoff[i] + k]) {
          ok = false;
          break;
        }
      if (ok) ++qansstupid[i];
    }
  }
}
void stress() {
  int mxsong = 1000, mxalph = 2, mxqlen = 50;
  nq = 1000;
  for (int rep = (0); rep < (100000); ++rep) {
    nsong = rand() % mxsong + 1;
    par[0] = -1, parc[0] = '-';
    int alph = rand() % mxalph + 1;
    for (int i = (1); i <= (nsong); ++i) {
      par[i] = rand() % i;
      parc[i] = 'a' + rand() % alph;
    }
    qoff[0] = 0;
    for (int i = (0); i < (nq); ++i) {
      qidx[i] = rand() % (nsong + 1);
      qlen[i] = rand() % mxqlen + 1;
      for (int j = (0); j < (qlen[i]); ++j)
        qs[qoff[i] + j] = 'a' + rand() % alph;
      qoff[i + 1] = qoff[i] + qlen[i];
    }
    qs[qoff[nq]] = '\0';
    solve();
    solvestupid();
    bool ok = true;
    for (int i = (0); i < (nq); ++i)
      if (qans[i] != qansstupid[i]) ok = false;
    if (ok) {
      if (rep % 100 == 0) printf(".");
      continue;
    }
    printf("err rep=%d\n", rep);
    printf("%d\n", nsong);
    for (int i = (1); i <= (nsong); ++i)
      if (par[i] == 0)
        printf("%d %c\n", 1, parc[i]);
      else
        printf("%d %d %c\n", 2, par[i], parc[i]);
    printf("%d\n", nq);
    for (int i = (0); i < (nq); ++i) {
      printf("%d ", qidx[i]);
      for (int j = (0); j < (qlen[i]); ++j) printf("%c", qs[qoff[i] + j]);
      puts("");
    }
    printf("have:");
    for (int i = (0); i < (nq); ++i) printf(" %d", qans[i]);
    puts("");
    printf("want:");
    for (int i = (0); i < (nq); ++i) printf(" %d", qansstupid[i]);
    puts("");
  }
}
int main() {
  run();
  return 0;
}
