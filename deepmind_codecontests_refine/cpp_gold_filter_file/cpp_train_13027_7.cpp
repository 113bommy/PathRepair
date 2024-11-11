#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)3e5 + 7;
const long long linf = (long long)1e18 + 7;
const int INF = (int)1e9 + 7;
const long double pi = 3.14159265359;
const double eps = 1e-6;
const int base = 1000 * 1000 * 1000;
const long long P = 37;
void boost() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long n, m, k;
long long a[maxn];
long long sx, sy, fx, fy;
vector<pair<int, int> > g[51][51];
bool u[51][51], u1[51][51];
void dfs(int x, int y) {
  u[x][y] = 1;
  for (pair<int, int> i : g[x][y]) {
    if (!u[i.first][i.second]) {
      dfs(i.first, i.second);
    }
  }
}
void dfs1(int x, int y) {
  u1[x][y] = 1;
  for (pair<int, int> i : g[x][y]) {
    if (!u1[i.first][i.second]) {
      dfs1(i.first, i.second);
    }
  }
}
map<int, vector<int> > poses;
int main() {
  boost();
  cin >> n;
  for (int i = 1; i <= n + n; ++i) {
    cin >> a[i];
    poses[a[i]].push_back(i);
  }
  long long nowpos1 = 1, nowpos2 = 1, ans = 0;
  for (int i = 1; i <= n; ++i) {
    bool fl1 = 0, fl2 = 0;
    if (abs(poses[i][0] - nowpos1) + (abs(poses[i][1] - nowpos2)) <=
        abs(poses[i][0] - nowpos2) + (abs(poses[i][1] - nowpos1))) {
      ans += abs(poses[i][0] - nowpos1) + (abs(poses[i][1] - nowpos2));
      nowpos1 = poses[i][0];
      nowpos2 = poses[i][1];
    } else {
      ans += abs(poses[i][0] - nowpos2) + (abs(poses[i][1] - nowpos1));
      nowpos2 = poses[i][0];
      nowpos1 = poses[i][1];
    }
  }
  cout << ans;
  return 0;
}
