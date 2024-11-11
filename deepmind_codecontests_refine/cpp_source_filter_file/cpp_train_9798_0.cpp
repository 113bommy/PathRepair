#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int maxm = 305;
long long arr[maxn];
long long arr1[maxn];
long long ma1[550][550];
long long ma2[550][550];
long long presum[maxn];
const long long mod = 998244353LL;
long long dp[maxn];
long long n, m, v, k, q, D, H, a, b, t, r, c, x, y;
string s;
long long heng[550];
long long shu[550];
long long jie[maxn], djie[maxn], res;
char matrix[2200][2200];
pair<int, int> dis[2200][2200];
bool visited[2200][2200];
struct Point {
  Point(int curx, int cury, int left, int right) {
    this->curx = curx;
    this->cury = cury;
    this->right = right;
    this->left = left;
  }
  int curx;
  int cury;
  int left;
  int right;
};
bool operator<(Point a, Point b) { return a.left + a.right > b.left + b.right; }
void bfs(int curx, int cury) {
  visited[curx][cury] = true;
  Point p(curx, cury, x, y);
  priority_queue<Point> q;
  q.push(p);
  while (q.size() > 0) {
    Point curp = q.top();
    q.pop();
    int dirx[] = {1, -1, 0, 0};
    int diry[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
      int nextx = curp.curx + dirx[i];
      int nexty = curp.cury + diry[i];
      if (nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= m &&
          !visited[nextx][nexty] && matrix[nextx][nexty] == '.') {
        int nextleft = curp.left;
        int nextright = curp.right;
        if (i == 2)
          nextright--;
        else if (i == 3)
          nextleft--;
        if (nextleft >= 0 && nextright >= 0) {
          visited[nextx][nexty] = true;
          Point nextp(nextx, nexty, nextleft, nextright);
          dis[nextx][nexty] = make_pair(nextleft, nextright);
          q.push(nextp);
        }
      }
    }
  }
}
int main() {
  cin >> n >> m;
  cin >> r >> c;
  cin >> x >> y;
  for (int i = 0; i < 2200; i++)
    for (int j = 0; j < 2200; j++) dis[i][j] = make_pair(99999, 99999);
  dis[r][c] = make_pair(0, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> matrix[i][j];
  }
  bfs(r, c);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (matrix[i][j] == '.') {
        if (visited[i][j]) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
