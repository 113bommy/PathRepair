#include <bits/stdc++.h>
using namespace std;
double pi = acos(-1);
struct comp {
  double x, y;
};
comp operator+(comp a, comp b) { return (comp){a.x + b.x, a.y + b.y}; }
comp operator-(comp a, comp b) { return (comp){a.x - b.x, a.y - b.y}; }
comp operator*(comp a, comp b) {
  return (comp){a.x * b.x - a.y * b.y, a.y * b.x + b.y * a.x};
}
comp fft[70000], a[70000], b[70000];
int n, m, t, f, rev[70000], v[105][3], s[105][70000], dis[105], vis[105],
    head[105], su[105][70000], cnt;
double dp[105][70000], dp2[105][70000];
struct edge {
  int t, next, v;
} ed[105 * 2];
void adde(int f, int t, int v) {
  ed[++cnt] = (edge){t, head[f], v};
  head[f] = cnt;
}
void dij(int s) {
  priority_queue<pair<long long, int> > st;
  st.push(make_pair(0, s));
  memset(vis, 0, sizeof(vis));
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  while (!st.empty()) {
    int v = st.top().second;
    st.pop();
    if (vis[v]) continue;
    vis[v] = 1;
    for (int i = head[v]; i; i = ed[i].next)
      if (dis[ed[i].t] > dis[v] + ed[i].v)
        dis[ed[i].t] = dis[v] + ed[i].v,
        st.push(make_pair(-dis[ed[i].t], ed[i].t));
  }
}
void dft(int s, comp *a, int t) {
  for (int i = 0; i < s; i++)
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) * (s >> 1)), fft[rev[i]] = a[i];
  for (int l = 2; l <= s; l <<= 1) {
    comp t1 = (comp){cos(pi * 2 / l), t * sin(pi * 2 / l)};
    for (int i = 0; i < s; i += l) {
      comp s = (comp){1, 0};
      for (int j = i; j < i + (l >> 1); j++, s = s * t1) {
        comp s1 = fft[j], s2 = fft[j + (l >> 1)] * s;
        fft[j] = s1 + s2;
        fft[j + (l >> 1)] = s1 - s2;
      }
    }
  }
  for (int i = 0; i < s; i++) {
    a[i] = fft[i];
    if (t == -1) a[i].x /= s, a[i].y /= s;
  }
}
void cdq(int l, int r) {
  if (l == r) {
    for (int i = 1; i < n; i++) dp2[i][l] = 1e17;
    for (int i = 1; i <= m; i++) {
      double tp = 1 - su[i][t - l] / 1e5;
      dp[i][l] += tp * (f + dis[v[i][1]]) + v[i][2];
      if (dp[i][l] < dp2[v[i][0]][l]) dp2[v[i][0]][l] = dp[i][l];
    }
    return;
  }
  int mid = (l + r) >> 1;
  cdq(mid + 1, r);
  for (int i = 1; i <= m; i++) {
    int l1 = 1;
    while (l1 < (r - l) * 3 / 2 + 5) l1 <<= 1;
    for (int j = 0; j < l1; j++) a[j].x = a[j].y = b[j].x = b[j].y = 0;
    for (int j = mid + 1; j <= r; j++) a[j - mid].x = dp2[v[i][1]][j];
    for (int j = 1; j <= r - l + 1; j++) b[r - l + 1 - j].x = s[i][j] / 1e5;
    dft(l1, a, 1);
    dft(l1, b, 1);
    for (int j = 0; j < l1; j++) a[j] = a[j] * b[j];
    dft(l1, a, -1);
    for (int j = l; j <= mid; j++) dp[i][j] += a[j + r - l + 1 - mid].x;
  }
  cdq(l, mid);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &t, &f);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &v[i][0], &v[i][1], &v[i][2]);
    adde(v[i][1], v[i][0], v[i][2]);
    for (int j = 1; j <= t; j++)
      scanf("%d", &s[i][j]), su[i][j] = su[i][j - 1] + s[i][j];
  }
  dij(n);
  cdq(0, t);
  printf("%.10lf\n", dp[1][0]);
}
