#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int n, d[410][410];
vector<int> vec[410][410];
double p[410], mmx[410];
double calc(int f) {
  double ans = 0;
  for (int l = 0; l < n; l++)
    if (!vec[f][l].empty()) {
      if (vec[f][l].size() == 1) {
        ans += 1.0 / n;
        continue;
      }
      for (int i = 1; i <= n; i++) p[i] = 0;
      vector<int> nxt;
      for (int v : vec[f][l]) {
        double first = 1.0 / n / vec[v][1].size();
        for (int w : vec[v][1]) {
          if (p[w] < 1e-9) nxt.push_back(w);
          p[w] += first;
        }
      }
      double mx = 0;
      for (int i = 1; i <= n; i++) {
        double s = 0;
        for (int w : nxt) smax(mmx[d[i][w]], p[w]);
        for (int w : nxt) s += mmx[d[i][w]], mmx[d[i][w]] = 0;
        smax(mx, s);
      }
      ans += mx;
    }
  return ans;
}
int main() {
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) d[i][j] = (i != j) * n;
  for (int i = 0, u, v; i < m; i++) {
    gn(u, v);
    d[u][v] = d[v][u] = 1;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) smin(d[i][j], d[i][k] + d[k][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) vec[i][d[i][j]].push_back(j);
  double ans = 0;
  for (int i = 1; i <= n; i++) smax(ans, calc(i));
  printf("%.12lf\n", ans);
  return 0;
}
