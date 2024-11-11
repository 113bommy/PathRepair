#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mod = (int)1e9 + 7;
const long long INF = 1000000000000000000LL;
const int WASTE = (int)2e5;
vector<int> v[(int)2e5 + 5];
bool visit[(int)2e5 + 5];
int m = 0, ans[(int)2e5 + 5];
void dfs(int x, int y, int z) {
  visit[x] = 1;
  int k = 1;
  for (auto ii : v[x]) {
    if (!visit[ii]) {
      if (k == y || k == z) k++;
      if (k == y || k == z) k++;
      ans[ii] = k;
      k++;
    }
  }
  for (auto ii : v[x]) {
    if (!visit[ii]) {
      dfs(ii, ans[x], ans[ii]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  memset(visit, 0, sizeof(visit));
  int i;
  for (int x = 0; x < n - 1; x++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
    if (v[a].size() > m) {
      m = v[a].size();
      i = a;
    }
    if (v[b].size() > m) {
      m = v[b].size();
      i = b;
    }
  }
  m++;
  ans[i] = 1;
  dfs(i, 1, 1);
  cout << m << "\n";
  for (int x = 1; x <= n; x++) cout << ans[x] << ' ';
  return 0;
}
