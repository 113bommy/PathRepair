#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000000")
#pragma GCC optimize("O3")
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000007LL;
const long long INF2 = 1000000007LL * 1000000007LL;
const long double EPS = 1e-4 / 2;
const int SIZE = 200100;
mt19937 rng(time(0));
uniform_int_distribution<int> uid(-1000000000, 1000000000);
const int SIZE_ = 200;
int n, t, xr, yr;
string s[10], c[10];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool exist(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n && s[x][y] != 'Z' && s[x][y] != 'Y';
}
vector<vector<int>> distR(10, vector<int>(10, INF));
int cntS, cntC;
vector<pair<int, int>> posC;
vector<vector<int>> g1;
vector<int> mt;
vector<int> used;
bool kun(int v) {
  if (used[v]) return 0;
  used[v] = 1;
  for (auto& i : g1[v]) {
    if (mt[i] == -1 || kun(mt[i])) {
      mt[i] = v;
      return 1;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'Z') {
        xr = i;
        yr = j;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    for (int j = 0; j < n; ++j) {
      if (isdigit(c[i][j])) {
        cntC += c[i][j] - '0';
        for (int rep_iter = 0; rep_iter < c[i][j] - '0'; ++rep_iter)
          posC.push_back({i, j});
      }
    }
  }
  queue<pair<int, int>> q;
  distR[xr][yr] = 0;
  q.push({xr, yr});
  while (q.size()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int xn = x + dx[i], yn = y + dy[i];
      if (exist(xn, yn) && distR[xn][yn] == INF) {
        distR[xn][yn] = distR[x][y] + 1;
        q.push({xn, yn});
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '0' || s[i][j] == 'Y' || s[i][j] == 'Z') continue;
      vector<vector<int>> d(n, vector<int>(n, INF));
      d[i][j] = 0;
      q.push({i, j});
      while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (d[x][y] >= t || d[x][y] >= distR[x][y]) continue;
        for (int k = 0; k < 4; ++k) {
          int xn = x + dx[k], yn = y + dy[k];
          if (exist(xn, yn) && d[xn][yn] == INF) {
            if (d[x][y] + 1 > t || d[x][y] + 1 > distR[xn][yn]) continue;
            d[xn][yn] = d[x][y] + 1;
            q.push({xn, yn});
          }
        }
      }
      vector<int> v;
      for (int k = 0; k < cntC; ++k) {
        if (d[posC[i].first][posC[i].second] < INF) v.push_back(k);
      }
      cntS += s[i][j] - '0';
      for (int rep_iter = 0; rep_iter < s[i][j] - '0'; ++rep_iter)
        g1.push_back(v);
    }
  }
  used.resize(cntS, 0);
  mt.resize(cntC, -1);
  int ans = 0;
  for (int i = 0; i < cntS; i++) {
    fill(used.begin(), used.end(), 0);
    if (kun(i)) ++ans;
  }
  cout << ans << '\n';
  return 0;
}
