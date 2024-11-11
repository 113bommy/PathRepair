#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
long long a[100100];
set<pair<int, int> > s;
int n, k, c[100100];
bool cmp(int i, int j) { return a[i] < a[j]; }
queue<int> q;
int flag[100100];
long long dis[100100];
void update(long long p) {
  for (int i = 0; i < k; i++) q.push(i), flag[i] = 1;
  while (!q.empty()) {
    int u = q.front(), v;
    q.pop();
    flag[u] = 0;
    if (dis[u] + p < dis[v = (p + u) % k]) {
      dis[v] = dis[u] + p;
      if (!flag[v]) q.push(v), flag[v] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!c[i]) continue;
    if (dis[a[i] % k] <= a[i] && !s.count(pair<int, int>(c[i], -i)))
      s.insert(pair<int, int>(c[i], -i));
  }
}
int main() {
  long long h;
  int m;
  cin >> h >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    scanf("%I64d %d", a + i, c + i);
    a[i]--;
  }
  memset(dis, 0x3f, sizeof(dis));
  dis[0] = 0;
  update(k);
  int tp, u, d;
  for (int i = 0; i < m; i++) {
    scanf("%d", &tp);
    if (tp == 1) {
      scanf("%I64d", &h);
      update(h);
    } else if (tp == 2) {
      scanf("%d %d", &u, &d);
      u--;
      if (!s.count(pair<int, int>(c[u], -u)))
        c[u] -= d;
      else
        s.erase(pair<int, int>(c[u], -u)),
            s.insert(pair<int, int>(c[u] -= d, -u));
    } else {
      if (s.empty())
        puts("0");
      else {
        int u = -(--s.end())->second;
        printf("%d\n", c[u]);
        c[u] = 0;
        s.erase(--s.end());
      }
    }
  }
  return 0;
}
