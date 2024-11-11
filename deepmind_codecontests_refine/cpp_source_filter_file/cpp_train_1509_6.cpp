#include <bits/stdc++.h>
using namespace std;
const int max_n = 2003;
const int max_m = 100000;
int n, m;
int s, t;
long long p[max_n + 1];
vector<int> neigh[max_n + 1];
vector<int> len[max_n + 1];
long long ds[max_n + 1];
long long dt[max_n + 1];
int w, h;
long long pts[max_n + 2][max_n + 2];
int cities[max_n + 2][max_n + 2];
long long pt_sum[max_n + 3][max_n + 3];
int c_sum[max_n + 3][max_n + 3];
long long x_score[max_n + 2][max_n + 2];
long long y_score[max_n + 2][max_n + 2];
bool ds_cmp(int v, int w) { return ds[v] < ds[w]; }
bool dt_cmp(int v, int w) { return dt[v] < dt[w]; }
void djik(int src, long long *dist) {
  bool seen[max_n + 1] = {};
  priority_queue<pair<long long, int> > pq;
  pq.push(pair<long long, int>(0, src));
  while (!pq.empty()) {
    long long d = -pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (seen[v]) continue;
    seen[v] = true;
    dist[v] = d;
    for (int i = 0; i < neigh[v].size(); i++) {
      int w = neigh[v][i];
      int dw = d + len[v][i];
      if (!seen[w]) pq.push(pair<long long, int>(-dw, w));
    }
  }
}
void solve_testcase() {
  djik(s, ds);
  djik(t, dt);
  map<long long, int> ds_i, dt_i;
  int pi[max_n + 1];
  for (int i = 1; i <= n; i++) pi[i] = i;
  sort(pi + 1, pi + n + 1, ds_cmp);
  w = 1;
  for (int i = 1; i <= n; i++) {
    long long len = ds[pi[i]];
    if (ds_i.count(len) != 0)
      continue;
    else
      ds_i[len] = w++;
  }
  h = 1;
  sort(pi + 1, pi + n + 1, dt_cmp);
  for (int i = 1; i <= n; i++) {
    long long len = dt[pi[i]];
    if (dt_i.count(len) != 0)
      continue;
    else
      dt_i[len] = h++;
  }
  for (int x = 0; x <= w + 1; x++)
    for (int y = 0; y <= h + 1; y++) {
      pts[x][y] = 0;
      cities[x][y] = 0;
    }
  for (int i = 1; i <= n; i++) {
    int x = ds_i[ds[i]];
    int y = dt_i[dt[i]];
    int num_pts = p[i];
    pts[x][y] += num_pts;
    cities[x][y]++;
  }
  for (int x = 0; x <= w + 1; x++) pt_sum[x][h + 2] = c_sum[x][h + 2] = 0;
  for (int y = 0; y <= h + 1; y++) pt_sum[w + 2][y] = c_sum[w + 2][y] = 0;
  for (int x = w + 1; x >= 0; x--)
    for (int y = h + 1; y >= 0; y--) {
      pt_sum[x][y] = pts[x][y] + pt_sum[x + 1][y] + pt_sum[x][y + 1] -
                     pt_sum[x + 1][y + 1];
      c_sum[x][y] = cities[x][y] + c_sum[x + 1][y] + c_sum[x][y + 1] -
                    c_sum[x + 1][y + 1];
      if (c_sum[x][y] == 0)
        x_score[x][y] = y_score[x][y] = 0;
      else {
        int x1 = x;
        while (c_sum[x][y] == c_sum[x1][y]) x1++;
        long long diff = (-pt_sum[x1][y] + pt_sum[x][y]);
        x_score[x][y] = diff + max(x_score[x1][y], -y_score[x1][y]);
        int y1 = y;
        while (c_sum[x][y] == c_sum[x][y1]) y1++;
        diff = (-pt_sum[x][y1] + pt_sum[x][y]);
        y_score[x][y] = diff + max(y_score[x][y1], -x_score[x][y1]);
      }
    }
  long long res = x_score[0][0];
  if (res > 0) printf("Break a heart\n");
  if (res == 0) printf("Flowers\n");
  if (res < 0) printf("Cry\n");
}
bool read_testcase() {
  if (scanf("%d %d", &n, &m) != 2) return false;
  scanf("%d %d", &s, &t);
  for (int i = 1; i <= n; i++) {
    int points;
    cin >> points;
    p[i] = (long long)points;
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d %d %d", &v, &u, &w);
    neigh[v].push_back(u);
    len[v].push_back(w);
    neigh[u].push_back(v);
    len[u].push_back(w);
  }
  return true;
}
int main(int argc, char **argv) {
  if (argc > 1 && argv[1][0] != 'x') freopen(argv[1], "r", stdin);
  if (argc > 2) freopen(argv[2], "w", stdout);
  int T = 1;
  clock_t cur, prev = clock();
  while (read_testcase()) {
    fprintf(stderr, ">>>Solving testcase %d<<<<\n", T);
    solve_testcase();
    cur = clock();
    int dur = (cur - prev) * 1000 / CLOCKS_PER_SEC;
    fprintf(stderr, "____Case %d done in %dms.\n", T, dur);
    prev = cur;
    T++;
  }
}
