#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6;
int dx[8] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[8] = {0, 1, -1, 0, 1, -1, -1, 1};
vector<long long> v[2001];
long long n, mx = 1;
bool vis[2001];
void dfs(long long n, long long hi) {
  vis[n] = 1;
  mx = max(mx, hi);
  for (int i = 0; i < v[n].size(); i++) {
    dfs(v[n][i], hi + 1);
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  std::ios::sync_with_stdio(false);
  cin >> n;
  long long x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x != -1) {
      v[x].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (v[i].size() != 0) dfs(i, 1);
  }
  cout << mx;
  return 0;
}
