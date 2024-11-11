#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double oo = 10e9;
const double eps = 10e-9;
const double pi = acos(-1.0);
const int maxn = 111;
int n, m;
vector<int> g[maxn];
vector<int> v[maxn];
int way[maxn];
int tot;
bool inq[maxn];
long long f[maxn];
double ans;
void bfs() {
  for (int i = 1; i <= n; i++) {
    way[i] = inf;
  }
  queue<int> q;
  while (!q.empty()) q.pop();
  memset(inq, false, sizeof(inq));
  q.push(1);
  inq[1] = true;
  way[1] = 0;
  int now, to, temp;
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (int i = 0; i < g[now].size(); i++) {
      to = g[now][i];
      temp = way[now] + 1;
      if (temp < way[to]) {
        way[to] = temp;
        if (!inq[to]) {
          inq[to] = true;
          q.push(to);
        }
      }
    }
    inq[now] = false;
  }
  return;
}
long long find(int x, int y) {
  memset(f, 0, sizeof(f));
  f[x] = 1;
  memset(inq, false, sizeof(inq));
  queue<int> q;
  inq[x] = true;
  q.push(x);
  int now, to;
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (int i = 0; i < g[now].size(); i++) {
      to = g[now][i];
      if (way[to] == (way[now] + 1)) {
        f[to] += f[now];
        if (!inq[to]) {
          inq[to] = true;
          q.push(to);
        }
      }
    }
  }
  return f[y];
}
double start() {
  bfs();
  memset(f, 0, sizeof(f));
  f[1] = 1;
  ans = 0.0;
  double d1, d2;
  long long t1, t2;
  double have = find(1, n);
  for (int i = 2; i <= n - 1; i++) {
    t1 = find(1, i);
    t2 = find(i, n);
    double temp = t1 * t2;
    temp *= 2.0;
    temp /= have;
    if (temp > ans) {
      ans = temp;
    }
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    v[i].clear();
  }
  int now, to;
  for (int i = 1; i <= m; i++) {
    cin >> now >> to;
    g[now].push_back(to);
    g[to].push_back(now);
  }
  printf("%.12lf\n", start());
  return 0;
}
