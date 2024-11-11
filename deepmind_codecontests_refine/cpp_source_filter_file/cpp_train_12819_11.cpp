#include <bits/stdc++.h>
using namespace std;
long long n;
long long r1, c1, r2, c2;
vector<string> v;
vector<vector<long long>> visited(51, vector<long long>(51, 0));
vector<vector<long long>> visited1(51, vector<long long>(51, 0));
vector<pair<long long, long long>> v1;
vector<pair<long long, long long>> v2;
void dfs(long long x, long long y) {
  if (x < 0 || x >= n || y < 0 || y >= n) return;
  if (v[x][y] == '1') {
    return;
  }
  if (visited[x][y]) return;
  v1.push_back({x, y});
  visited[x][y] = 1;
  dfs(x - 1, y);
  dfs(x, y - 1);
  dfs(x + 1, y);
  dfs(x, y + 1);
}
void dfs1(long long x, long long y) {
  if (x < 0 || x >= n || y < 0 || y >= n) return;
  if (v[x][y] == '1') {
    return;
  }
  if (visited1[x][y]) return;
  v2.push_back({x, y});
  visited1[x][y] = 1;
  dfs1(x - 1, y);
  dfs1(x, y - 1);
  dfs1(x + 1, y);
  dfs1(x, y + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    cin >> n;
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    r1--;
    r2--;
    c1--;
    c2--;
    for (long long i = 0; i < n; i++) {
      string h;
      cin >> h;
      v.push_back(h);
    }
    dfs(r1, c1);
    dfs1(r2, c2);
    long long ans = n * n;
    if (v1 == v2)
      cout << 0 << "\n";
    else {
      long long a = v1.size(), b = v2.size();
      for (long long i = 0; i < a; i++) {
        for (long long j = 0; j < b; j++) {
          long long Y =
              (v1[i].second - v2[j].second) * (v1[i].second - v2[j].second) +
              (v1[i].first - v2[j].first) * (v1[i].first - v2[j].first);
          ans = min(ans, Y);
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
