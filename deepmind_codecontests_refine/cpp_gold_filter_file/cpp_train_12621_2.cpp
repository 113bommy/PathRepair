#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
int pa[N], sz[N];
long long find_pa(long long pos) {
  if (pa[pos] != pos) pa[pos] = find_pa(pa[pos]);
  return pa[pos];
}
void join(int a, int b) {
  int x = find_pa(a), y = find_pa(b);
  if (x != y) {
    if (sz[x] >= sz[y])
      sz[x] += sz[y], pa[y] = x;
    else
      sz[y] += sz[x], pa[x] = y;
  }
}
void dsu_init(long long n) {
  for (int i = 0, ggdem = n; i < ggdem; ++i) pa[i] = i, sz[i] = 1;
}
long long nxt[N];
long long pr[N][4];
long long vis[N];
long long c[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  memset((pr), (-1), sizeof(pr));
  while (t--) {
    long long n, m;
    cin >> n >> m;
    char a[n][m];
    char b[n * m];
    for (int i = 0, ggdem = n; i < ggdem; ++i) {
      for (int j = 0, ggdem = m; j < ggdem; ++j) {
        cin >> b[m * i + j];
      }
    }
    string RDLU = "RDLU";
    for (int i = 0, ggdem = n; i < ggdem; ++i) {
      for (int j = 0, ggdem = m; j < ggdem; ++j) {
        cin >> a[i][j];
        for (int ii = 0, ggdem = 4; ii < ggdem; ++ii) {
          if (RDLU[ii] == a[i][j]) {
            a[i][j] = ii;
            break;
          }
        }
      }
    }
    vector<long long> d = {1, m, -1, -m};
    dsu_init(n * m);
    for (int i = 0, ggdem = n; i < ggdem; ++i) {
      for (int j = 0, ggdem = m; j < ggdem; ++j) {
        long long p = d[a[i][j]] + m * i + j;
        nxt[m * i + j] = p;
        pr[p][a[i][j]] = (m * i + j);
        join(m * i + j, p);
      }
    }
    for (int i = 0, ggdem = n * m; i < ggdem; ++i) vis[i] = 0;
    for (int i = 0, ggdem = n * m; i < ggdem; ++i) c[i] = -1;
    long long res[2] = {0, 0};
    for (int i = 0, ggdem = n * m; i < ggdem; ++i) {
      long long pp = find_pa(i);
      if (!vis[pp]) {
        long long van = 1;
        vis[pp] = van++;
        long long va = pp;
        va = nxt[va];
        while (!vis[va]) {
          vis[va] = van++;
          va = nxt[va];
        }
        long long len = van - vis[va];
        long long hay[len];
        memset((hay), (0), sizeof(hay));
        queue<long long> q;
        q.push(va);
        c[va] = 0;
        hay[0] = (b[va] == '0');
        while (((int)q.size())) {
          long long f = q.front();
          q.pop();
          for (int j = 0, ggdem = 4; j < ggdem; ++j) {
            long long u = pr[f][j];
            if (u != -1 && c[u] == -1) {
              q.push(u);
              c[u] = (c[f] + 1);
              if (c[u] >= len) c[u] -= len;
              if (b[u] == '0') hay[c[u]] = 1;
              if (vis[u] == 0) vis[u]++;
            }
          }
        }
        res[0] += len;
        for (int j = 0, ggdem = len; j < ggdem; ++j) res[1] += hay[j];
      }
    }
    cout << res[0] << " " << res[1] << "\n";
    for (int i = 0, ggdem = n * m; i < ggdem; ++i) {
      nxt[i] = 0;
      for (int j = 0, ggdem = 4; j < ggdem; ++j) pr[i][j] = -1;
    }
  }
  return 0;
}
