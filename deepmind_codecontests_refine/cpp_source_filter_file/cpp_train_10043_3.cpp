#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = (1 << 16) + 5;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
pair<int, int> a[maxn];
queue<int> q;
vector<pair<int, int> > g;
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  for (int i = 0; i < n; i++) {
    if (a[i].first == 1) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (a[u].first == 0) continue;
    int v = a[u].second;
    g.push_back(make_pair(u, v));
    a[v].second ^= u;
    a[v].first--;
    if (a[v].second == 1) {
      q.push(v);
    }
  }
  printf("%d\n", (int)(g).size());
  for (int i = 0; i < (int)(g).size(); i++) {
    printf("%d %d\n", g[i].first, g[i].second);
  }
  return 0;
}
