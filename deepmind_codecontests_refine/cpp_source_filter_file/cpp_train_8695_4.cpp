#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
struct node {
  long long int value;
  long long int x;
  long long int y;
};
long long int a[1005][1005], ans[1005][1005], cnt;
node p[1005][1005];
vector<node> b;
long long int vis[1005][1005];
bool func(node l, node r) { return (l.value < r.value); }
node findset(long long int xx, long long int yy) {
  if (p[xx][yy].x == xx && p[xx][yy].y == yy) return p[xx][yy];
  return p[xx][yy] = findset(p[xx][yy].x, p[xx][yy].y);
}
void mergeset(long long int x1, long long int y1, long long int x2,
              long long int y2) {
  if (a[x1][y1] > a[x2][y2]) return;
  node p1 = findset(x1, y1);
  node p2 = findset(x2, y2);
  p[p2.x][p2.y].value += p1.value;
  p[p1.x][p1.y] = p2;
}
void dfs(long long int xx, long long int yy, long long int v) {
  if (vis[xx][yy]) return;
  vis[xx][yy] = 1;
  if (a[xx][yy] < v || cnt <= 0) {
    a[xx][yy] = 0;
    return;
  }
  ans[xx][yy] = v;
  cnt--;
  dfs(xx - 1, yy, v);
  dfs(xx, yy - 1, v);
  dfs(xx + 1, yy, v);
  dfs(xx, yy + 1, v);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, k;
  cin >> n >> m >> k;
  memset(a, 0, sizeof(a));
  for (long long int i = 1; i < n + 1; i++) {
    for (long long int j = 1; j < m + 1; j++) {
      cin >> a[i][j];
      p[i][j] = {1, i, j};
      b.push_back({a[i][j], i, j});
    }
  }
  sort(b.begin(), b.end(), func);
  reverse(b.begin(), b.end());
  long long int V, xx, yy;
  cnt = -1;
  for (long long int i = 1; i < b.size(); i++) {
    xx = b[i].x, yy = b[i].y;
    mergeset(xx, yy, xx - 1, yy);
    mergeset(xx, yy, xx, yy - 1);
    mergeset(xx, yy, xx + 1, yy);
    mergeset(xx, yy, xx, yy + 1);
    if (k % b[i].value == 0) {
      node pp = findset(xx, yy);
      if (k / (b[i].value) <= pp.value) {
        cnt = k / (b[i].value);
        V = b[i].value;
        break;
      }
    }
  }
  if (cnt == -1) {
    cout << "NO";
    return 0;
  }
  memset(ans, 0, sizeof(ans));
  memset(vis, 0, sizeof(vis));
  dfs(xx, yy, V);
  cout << "YES" << endl;
  for (long long int i = 1; i < n + 1; i++) {
    for (long long int j = 1; j < m + 1; j++) cout << ans[i][j] << " ";
    cout << endl;
  }
}
