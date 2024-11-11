#include <bits/stdc++.h>
using namespace std;
const int MOD = 993244853;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) {
  if (a == 0 || b == 0) return a + b;
  return a * (b / gcd(a, b));
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int ddx[] = {-1, -2, 1, -2, 2, -1, 2, 1}, ddy[] = {-2, -1, -2, 1, -1, 2, 1, 2};
int cnt[50];
const int S = 5053, T = 5054;
int n, m, k, d, c;
struct Edge {
  int to, r, c;
  Edge* ori;
  Edge* rev;
  Edge(int T, int R, int C) { to = T, r = R, c = C; }
};
vector<Edge*> v[5055];
inline int z(int x, int t) { return 101 * x + t; }
void addedge(int f, int t, int r, int c) {
  Edge* ori = new Edge(t, r, c);
  Edge* rev = new Edge(f, 0, -c);
  ori->rev = rev;
  rev->rev = ori;
  v[f].push_back(ori);
  v[t].push_back(rev);
}
bool inQ[5055];
int dist[5055];
pair<int, int> p[5055];
int main() {
  scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
  for (int(i) = (0); (i) <= (k - 1); (i) += (1)) {
    int x;
    scanf("%d", &x);
    cnt[x - 1]++;
  }
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    if (cnt[i] > 0) addedge(S, z(i, 0), cnt[i], 0);
    for (int(j) = (0); (j) <= (99); (j) += (1))
      addedge(z(i, j), z(i, j + 1), 987654321, 0);
    if (i == 0) {
      for (int(j) = (0); (j) <= (100); (j) += (1))
        addedge(z(i, j), T, 987654321, c * j);
    }
  }
  for (int(i) = (0); (i) <= (m - 1); (i) += (1)) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    for (int(j) = (0); (j) <= (99); (j) += (1)) {
      for (int(l) = (1); (l) <= (k); (l) += (1)) {
        addedge(z(x, j), z(y, j + 1), 1, d * (2 * l - 1));
        addedge(z(y, j), z(x, j + 1), 1, d * (2 * l - 1));
      }
    }
  }
  int ans = 0;
  while (1) {
    memset((inQ), 0, sizeof(inQ));
    ;
    fill(dist, dist + 5055, 987654321);
    fill(p, p + 5055, pair<int, int>(-1, -1));
    queue<int> q;
    q.push(S);
    dist[S] = 0;
    inQ[S] = 1;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      inQ[x] = 0;
      for (int i = 0; i < v[x].size(); i++) {
        int next = v[x][i]->to;
        if (dist[next] > dist[x] + v[x][i]->c && v[x][i]->r > 0) {
          dist[next] = dist[x] + v[x][i]->c;
          p[next] = pair<int, int>(x, i);
          if (!inQ[next]) {
            q.push(next);
            inQ[next] = 1;
          }
        }
      }
    }
    if (p[T].first == -1) break;
    int flow = 987654321;
    for (int i = T; i != S; i = p[i].first) {
      flow = min(flow, v[p[i].first][p[i].second]->r);
    }
    for (int i = T; i != S; i = p[i].first) {
      v[p[i].first][p[i].second]->r -= flow;
      v[p[i].first][p[i].second]->rev->r += flow;
      ans += v[p[i].first][p[i].second]->c * flow;
    }
  }
  printf("%d", ans);
}
