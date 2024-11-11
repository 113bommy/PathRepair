#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, k;
vector<pair<int, int> > g[N];
vector<pair<int, int> > arr[N];
const int K = 15;
bool bad[K][K][K][K];
vector<int> v;
int ans = 0;
void calc(int i) {
  if (i == (int)v.size()) {
    ans++;
    return;
  }
  bool good;
  for (int j = 0; j <= i; j++) {
    v[i] = j;
    good = true;
    for (int k = 0; k <= i; k++) {
      if (bad[i][j][k][v[k]]) {
        good = false;
        break;
      }
    }
    if (!good) continue;
    calc(i + 1);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  v.resize(k, 0);
  for (int a, b, c, i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    g[a].push_back(make_pair(c, b));
  }
  for (int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
    for (int j = 0; j < (int)g[i].size(); j++) {
      arr[g[i][j].second].push_back(make_pair((int)g[i].size() - 1, j));
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(arr[i].begin(), arr[i].end());
    for (int j = 0; j + 1 < (int)arr[i].size(); j++) {
      if (arr[i][j] == arr[i][j + 1])
        bad[arr[i][j].first][arr[i][j].second][arr[i][j].first]
           [arr[i][j].second] = true;
    }
    arr[i].resize(unique(arr[i].begin(), arr[i].end()) - arr[i].begin());
    for (int j = 0; j < (int)arr[i].size(); j++) {
      for (int k = 0; k < (int)arr[i].size(); k++) {
        if (j == k) continue;
        bad[arr[i][j].first][arr[i][j].second][arr[i][k].first]
           [arr[i][k].second] = true;
      }
    }
  }
  calc(0);
  cout << ans << endl;
  return 0;
}
