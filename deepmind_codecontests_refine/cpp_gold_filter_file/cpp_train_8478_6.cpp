#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T MAX(T a, T b) {
  if (a > b) return a;
  return b;
}
template <class T>
inline T MIN(T a, T b) {
  if (a < b) return a;
  return b;
}
template <class T>
inline T ABS(T x) {
  if (x < 0) return -x;
  return x;
}
inline void OPEN(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const static int inf = 1000000000;
int n, m;
int g[100005], v[100005], b[100005], res[100005], vis[100005] = {};
int main() {
  scanf("%d%d", &n, &m);
  for (int(i) = (1); (i) <= (n); ++(i)) scanf("%d", &g[i]);
  for (int(i) = (1); (i) <= (m); ++(i)) scanf("%d", &v[i]);
  for (int(i) = (1); (i) <= (m); ++(i)) scanf("%d", &b[i]);
  res[0] = 0;
  for (int(i) = (1); (i) <= (m); ++(i)) {
    int now = (v[i] + res[i - 1] - 1) % n + 1;
    while (b[i] && vis[now] < b[i]) {
      if (vis[now] == 0) res[i]++;
      vis[now] = b[i];
      b[i]--;
      now = g[now];
    }
  }
  for (int(i) = (1); (i) <= (m); ++(i)) printf("%d\n", res[i]);
}
