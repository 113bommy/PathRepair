#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline _T sqr(const _T& x) {
  return x * x;
}
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-11;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
int n, m, k, nm;
int b[82][82];
int buf[(82 * 82 + 2) * 22];
int* a[82 * 82 + 2];
int e[82 * 82 * 16 + 100][5];
int d[82 * 82 + 2];
int pa[82 * 82 + 2];
int po[82 * 82 + 2];
int u[82 * 82 + 2];
void add_edge(int v1, int v2, int cc, int w) {
  e[k][0] = v1;
  e[k][1] = v2;
  e[k][2] = cc;
  e[k][3] = 0;
  e[k][4] = w;
  a[v1][++a[v1][0]] = k;
  k++;
  e[k][0] = v2;
  e[k][1] = v1;
  e[k][2] = 0;
  e[k][3] = 0;
  e[k][4] = -w;
  a[v2][++a[v2][0]] = k;
  k++;
}
const int MID = 1500000;
pair<int, int> q[MID * 2];
__attribute__((optimize(3))) int find(int st, int en) {
  memset(d, 0x3f, sizeof(d));
  d[st] = 0;
  int qb = MID, qe = MID;
  memset((u), 0, sizeof(u));
  q[qe++] = make_pair(d[st], st);
  u[st] = 1;
  while (qb != qe) {
    pair<int, int> tmp = q[qb++];
    int v = tmp.second;
    int dd = d[v];
    u[v] = 2;
    for (int i1 = (1); i1 <= (int)(a[v][0]); i1++) {
      int i = a[v][i1];
      int v2 = e[i][1];
      if (e[i][2] > e[i][3] && d[v2] > dd + e[i][4] + po[v] - po[v2]) {
        d[v2] = dd + e[i][4] + po[v] - po[v2];
        pa[v2] = i;
        if (u[v2] == 2) {
          q[--qb] = make_pair(d[v2], v2);
          u[v2] = 1;
        } else if (!u[v2]) {
          q[qe++] = make_pair(d[v2], v2);
          u[v2] = 1;
        }
      }
    }
  }
  for (int i = 0; i < (int)(en + 1); i++) {
    po[i] += d[i];
  }
  return d[en];
}
int flow(int st, int en) {
  int ans = 0;
  memset((po), 0, sizeof(po));
  for (int i = 0; i < (int)(nm / 2); i++) {
    find(st, en);
    int t = en;
    while (t != st) {
      int q = pa[t];
      ans += e[q][4];
      e[q][3]++;
      e[q ^ 1][3]--;
      t = e[q][0];
    }
  }
  return ans;
}
int main() {
  cout << setiosflags(ios::fixed) << setprecision(10);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      scanf("%d", &b[i][j]);
    }
  }
  nm = n * m;
  int zz = 0;
  for (int i = 0; i < (int)(nm); i++) {
    a[i] = buf + zz;
    zz += 22;
  }
  k = 0;
  int st = nm;
  int en = st + 1;
  a[st] = buf + zz;
  zz += 82 * 82 + 2;
  a[en] = buf + zz;
  zz += 82 * 82 + 2;
  memset((buf), 0, sizeof(buf));
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      for (int l = 0; l < (int)(4); l++) {
        int x = i + dx[l];
        int y = j + dy[l];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        add_edge((i * m + j), (x * m + y), 1, b[i][j] != b[x][y]);
      }
      if ((i + j) & 1)
        add_edge(st, (i * m + j), 1, 0);
      else
        add_edge((i * m + j), en, 1, 0);
    }
  }
  int ans = flow(st, en);
  printf("%d\n", ans);
  return 0;
}
