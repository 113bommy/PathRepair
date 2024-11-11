#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int dik[] = {1, 1, 2, 2, -1, -1, -2, -2};
int djk[] = {2, -2, 1, -1, -2, 2, -1, 1};
long long gcd(long long x, long long y) { return !y ? x : gcd(y, x % y); }
bool vis[5][5];
int main() {
  int n, m, k, ans = 0;
  cin >> n >> m >> k;
  vector<pair<int, int> > in(k);
  for (int i = 0; i < int(k); i++) {
    cin >> in[i].first >> in[i].second;
    vis[in[i].first][in[i].second] = 1;
    if (!ans && ((vis[in[i].first][in[i].second + 1] &&
                  vis[in[i].first + 1][in[i].second] &&
                  vis[in[i].first + 1][in[i].second + 1] &&
                  in[i].first + 1 <= n && in[i].second + 1 <= m) ||
                 (vis[in[i].first][in[i].second - 1] &&
                  vis[in[i].first + 1][in[i].second] &&
                  vis[in[i].first + 1][in[i].second - 1] &&
                  in[i].second - 1 >= 1 && in[i].first + 1 <= n) ||
                 (vis[in[i].first - 1][in[i].second] &&
                  vis[in[i].first - 1][in[i].second + 1] &&
                  vis[in[i].first][in[i].second + 1] && in[i].first - 1 >= 1 &&
                  in[i].second + 1 <= m) ||
                 (vis[in[i].first][in[i].second - 1] &&
                  vis[in[i].first - 1][in[i].second] &&
                  vis[in[i].first - 1][in[i].second - 1] &&
                  in[i].second - 1 >= 1 && in[i].first - 1 >= 1))) {
      ans = i + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
