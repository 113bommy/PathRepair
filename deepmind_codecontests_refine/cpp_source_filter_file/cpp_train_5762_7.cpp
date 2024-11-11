#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
const int maxn = 2100;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const double eps = 1e-5;
int n, c1, c2;
int a[maxn][maxn];
bool vis[maxn][maxn];
pair<int, int> k[maxn];
void bfs(int x, int y) {
  int mxx, mxy, mnx, mny, sum = 0;
  mxx = mxy = -1;
  mny = mnx = n + 1;
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  vis[x][y] = true;
  while (!q.empty()) {
    sum++;
    x = q.front().first, y = q.front().second;
    k[y].first = min(k[y].first, x);
    k[y].second = max(k[y].second, x);
    mxx = max(mxx, x);
    mxy = max(mxy, y);
    mnx = min(mnx, x);
    mny = min(mny, y);
    q.pop();
    for (int i = 0; i < 4; i++)
      if (!vis[x + dx[i]][y + dy[i]] && a[x + dx[i]][y + dy[i]]) {
        q.push(make_pair(x + dx[i], y + dy[i]));
        vis[x + dx[i]][y + dy[i]] = true;
      }
  }
  bool f = ((mny - mxy) * (mny - mxy)) + ((k[mny].first - k[mxy].second) *
                                          (k[mny].first - k[mxy].second)) <
               ((mxy - mny + 3) * (mxy - mny + 3)) &&
           sum > ((mxx - mnx) * (mxx - mnx)) * 0.73 &&
           sum < ((mxx - mnx) * (mxx - mnx)) * 0.83;
  if (f)
    c1++;
  else
    c2++;
  for (int i = mny; i <= mxy; i++) k[i] = make_pair(n + 1, -1);
}
int main() {
  cin >> n;
  for (int i = 0; i < maxn; i++) k[i] = make_pair(n + 1, -1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!vis[i][j] && a[i][j] == 1) bfs(i, j);
    }
  }
  cout << c1 << ' ' << c2;
  return 0;
}
