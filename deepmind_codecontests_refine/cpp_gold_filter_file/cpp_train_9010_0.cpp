#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "yes" : "no");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
int b, p[13], t[44][24], R[50], CC[40], T;
int tar[50];
int As;
vector<pair<pair<int, int>, pair<int, int>>> vans;
const int maxn = 65;
int edge[maxn][maxn];
int vis[maxn];
int cx[maxn], cy[maxn];
int nx, ny;
int line(int u) {
  for (int v = 0; v <= ny; v++) {
    if (edge[u][v] && !vis[v]) {
      vis[v] = 1;
      if (cy[v] == -1 || line(cy[v])) {
        cx[u] = v;
        cy[v] = u;
        return 1;
      }
    }
  }
  return 0;
}
int dgx[105], dgy[105];
int id[33];
void cal() {
  int M = m;
  for (int(i) = 1; (i) <= (int)(m); (i)++) id[i] = i;
  for (int(j) = 0; (j) < (int)(m); (j)++)
    if (As & (1 << j)) {
      M++;
      id[M] = j + 1;
      int J = j + 1;
      int ty = 0;
      for (int(i) = 1; (i) <= (int)(n); (i)++) {
        if (t[i][J] % 2 == 0) {
          t[i][J] /= 2;
          t[i][M] = t[i][J];
        } else {
          int hf = t[i][J] / 2;
          if (ty == 0) {
            t[i][J] = hf + 1;
            t[i][M] = hf;
          } else {
            t[i][J] = hf;
            t[i][M] = hf + 1;
          }
          ty ^= 1;
        }
      }
    }
  nx = ny = n + M;
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    for (int(j) = 1; (j) <= (int)(M); (j)++) {
      edge[i][j] = t[i][j];
      dgx[i] += t[i][j];
      dgy[j] += t[i][j];
      edge[n + j][M + i] = t[i][j];
    }
  for (int(i) = 1; (i) <= (int)(n); (i)++) edge[i][M + i] = T - dgx[i];
  for (int(j) = 1; (j) <= (int)(M); (j)++) edge[n + j][j] = T - dgy[j];
  for (int tt = 0; tt < T;) {
    memset(cx, 0xff, sizeof(cx));
    memset(cy, 0xff, sizeof(cy));
    for (int i = 1; i <= nx; i++) {
      if (cx[i] == -1) {
        memset(vis, 0, sizeof(vis));
        line(i);
      }
    }
    int mn = T;
    for (int(i) = 1; (i) <= (int)(nx); (i)++) mn = min(mn, edge[i][cx[i]]);
    for (int(i) = 1; (i) <= (int)(nx); (i)++) edge[i][cx[i]] -= mn;
    for (int(i) = 1; (i) <= (int)(n); (i)++)
      if (cx[i] <= M) {
        int u = cx[i];
        vans.push_back({{i, id[u]}, {tt, mn}});
      }
    tt += mn;
  }
  printf("%d\n", vans.size());
  for (auto p : vans) {
    printf("%d %d %d %d\n", p.first.first, p.first.second, p.second.first,
           p.second.second);
  }
}
void fmain() {
  scanf("%d%d%d", &n, &m, &b);
  for (int(i) = 1; (i) <= (int)(m); (i)++) scanf("%d", p + i);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d", &k);
    for (int(j) = 0; (j) < (int)(k); (j)++) {
      int x, y;
      scanf("%d%d", &x, &y);
      t[i][x] = y;
      R[i] += y;
      CC[x] += y;
    }
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++) T = max(T, R[i]);
  int cT = (1 << 30);
  for (int s = 0; s < (1 << m); s++) {
    int ss = 0;
    for (int(j) = 0; (j) < (int)(m); (j)++)
      if (s & (1 << j)) ss += p[j + 1];
    if (b < ss) continue;
    int tmp = 0;
    for (int(j) = 0; (j) < (int)(m); (j)++)
      if (s & (1 << j)) {
        tmp = max(tmp, (CC[j + 1] + 1) / 2);
      } else
        tmp = max(tmp, CC[j + 1]);
    if (tmp < cT) {
      cT = tmp;
      As = s;
    }
  }
  T = max(T, cT);
  printf("%d\n", T);
  for (int(j) = 0; (j) < (int)(m); (j)++) printf("%d", (As & (1 << j)) ? 1 : 0);
  puts("");
  cal();
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain();
  }
  return 0;
}
