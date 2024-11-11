#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T& x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T& x, L y) {
  return x > y ? (x = y, 1) : 0;
}
const int maxn = 5e2 + 17;
int n, ans[maxn], dis[maxn][maxn], v[maxn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> dis[i][j];
  for (int i = 0; i < n; i++) cin >> v[i], v[i]--;
  reverse(v, v + n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++)
      for (int k = 0; k < i; k++)
        smin(dis[v[i]][v[k]], dis[v[i]][v[j]] + dis[v[j]][v[k]]),
            smin(dis[v[k]][v[i]], dis[v[k]][v[j]] + dis[v[j]][v[i]]);
    for (int j = 0; j < i; j++)
      for (int k = 0; k < i; k++)
        smin(dis[v[j]][v[k]], dis[v[j]][v[i]] + dis[v[i]][v[k]]),
            smin(dis[v[k]][v[j]], dis[v[k]][v[i]] + dis[v[i]][v[j]]);
    for (int k = 0; k <= i; k++)
      for (int j = 0; j <= i; j++) ans[i] += dis[v[k]][v[j]];
  }
  reverse(ans, ans + n);
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
