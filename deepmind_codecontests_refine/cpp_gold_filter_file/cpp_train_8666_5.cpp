#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
using namespace std;
using lld = long long int;
using pll = pair<lld, lld>;
using lf = float;
using pff = pair<lf, lf>;
using pii = pair<int, int>;
int n, m;
vector<int> v[2][1009];
int dfs_cnt;
int re[1009];
int rev_re[1009];
pii qs;
int b[1009];
int bl;
int d[2][1009];
int p[2][1009];
bool dfs(int type, int dep, int si, int bti, int pi) {
  d[type][si] = dep;
  p[type][si] = pi;
  int ri = 0;
  bool ret = false;
  if (si == bti) ret = true;
  for (int i = 0; i < v[type][si].size(); i++) {
    int j = v[type][si][i];
    if (pi == j) continue;
    if (dfs(type, dep + 1, j, bti, si)) {
      ri = i;
      ret = true;
    }
  }
  if (ri != 0) {
    swap(v[type][si][0], v[type][si][ri]);
  }
  return ret;
}
void ask() {
  printf("? %d", bl);
  int i, j, k;
  for (i = 0; i < bl; i++) {
    printf(" %d", b[i] + 1);
  }
  printf("\n");
  fflush(stdout);
}
void receive() {
  int i, j, k;
  scanf("%d %d", &qs.first, &qs.second);
  qs.first--;
  if (qs.second == -1) exit(0);
  m++;
}
int qi, qj, qd;
void dfs_2(int type, int dep, int tdep, int qdep, int si, int pi) {
  int i = 0;
  if (d[type][si] >= tdep) {
    b[bl++] = si;
  }
  if (d[type][si] == qdep) return;
  if (pi == -1) {
    i = 1;
  }
  for (; i < v[type][si].size(); i++) {
    int j = v[type][si][i];
    if (pi == j) continue;
    dfs_2(type, dep + 1, tdep, qdep, j, si);
  }
}
int main() {
  int i, j, k;
  int t = 1, tv = 0;
  scanf("%d", &t);
  char tmp[99];
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      v[0][i].clear();
      v[1][i].clear();
    }
    for (i = 1; i < n; i++) {
      scanf("%d %d", &j, &k);
      j--;
      k--;
      v[0][j].push_back(k);
      v[0][k].push_back(j);
      v[1][j].push_back(k);
      v[1][k].push_back(j);
    }
    if (n == 2) {
      printf("! 1 2\n");
      fflush(stdout);
      scanf("%s", tmp);
      continue;
    }
    m = 0;
    bl = n;
    for (i = 0; i < n; i++) {
      b[i] = i;
    }
    ask();
    receive();
    qi = qs.first;
    qd = qs.second;
    bl = 0;
    for (i = 0; i < n; i++) {
      if (i == qi) continue;
      b[bl++] = i;
    }
    ask();
    receive();
    qj = qs.first;
    while (1) {
      dfs(0, 0, qi, qj, -1);
      dfs(1, 0, qj, qi, -1);
      if (d[0][qj] == qd) break;
      bl = 0;
      int diff = qd - d[0][qj];
      dfs_2(0, 0, (diff + 1) / 2, diff, qi, -1);
      dfs_2(1, 0, (diff + 1) / 2, diff, qj, -1);
      ask();
      receive();
      int qk = qs.first;
      int me = qk;
      while (1) {
        if (me == qj) {
          qj = qk;
          break;
        }
        if (me == qi) {
          qi = qk;
          break;
        }
        me = p[0][me];
      }
    }
    printf("! %d %d\n", qi + 1, qj + 1);
    fflush(stdout);
    scanf("%s", tmp);
  }
  return 0;
}
