#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxw = 1e4 + 5;
int readint() {
  int x = 0, f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    (s = getchar());
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    (s = getchar());
  }
  return x * f;
}
int vis[maxn], a[maxn];
int dp[maxw][maxn];
vector<pair<int, int> > vec;
int main() {
  int n = readint();
  for (int i = 1; i <= n; i++) {
    a[i] = readint();
    vis[a[i]]++;
  }
  for (int i = 1; i <= 100; i++) {
    if (vis[i] == 0) continue;
    vec.push_back(make_pair(i, vis[i]));
  }
  dp[0][0] = 1;
  if (vec.size() <= 2) return !printf("0");
  for (int i = 0; i < vec.size(); i++) {
    int v = vec[i].first, cnt = vec[i].second;
    for (int j = 1e4; j >= 0; j--) {
      for (int w = 1; w <= n; w++) {
        for (int t = 1; t <= cnt && t <= w && j - v * t >= 0; t++) {
          dp[j][w] += dp[j - v * t][w - t];
        }
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < vec.size(); i++) {
    int v = vec[i].first, cnt = vec[i].second;
    for (int j = 1; j <= cnt; j++) {
      if (dp[j * v][j] == 1) ans = max(ans, j);
    }
  }
  cout << ans;
  return 0;
}
