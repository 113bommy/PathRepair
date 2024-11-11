#include <bits/stdc++.h>
using namespace std;
pair<int, int> t[1000100];
vector<int> edge[1040];
bool visited[1040];
int ile_skladowych = 0;
multiset<pair<long long, long long>> s[10000];
void dfs(int x) {
  s[ile_skladowych].insert(pair<long long, long long>(t[x].first, t[x].second));
  visited[x] = true;
  for (int i : edge[x]) {
    if (!visited[i]) {
      dfs(i);
    }
  }
}
long long dp[2010][2010];
int main() {
  ios::sync_with_stdio(false);
  int n, m, w, x, y;
  cin >> n >> m >> w;
  for (int i = 1; i <= n; i++) {
    cin >> t[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i].second;
  }
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
      ile_skladowych++;
    }
  }
  for (int i = 0; i < ile_skladowych; i++) {
    long long waga = 0;
    long long wartosc = 0;
    for (auto p : s[i]) {
      waga = waga + p.first;
      wartosc = wartosc + p.second;
    }
    s[i].insert(pair<long long, long long>(waga, wartosc));
  }
  for (int j = 0; j < ile_skladowych; j++) {
    if (j != 0) {
      for (int i = 0; i <= w; i++) {
        dp[i][j] = dp[i][j - 1];
      }
    }
    for (int k = w; k >= 1; k--) {
      for (auto p : s[j]) {
        if (k >= p.first) {
          dp[k][j] = max(dp[k][j], dp[k - p.first][j] + p.second);
        }
      }
    }
  }
  long long q = 0;
  for (int i = 0; i < ile_skladowych; i++) {
    q = max(q, dp[w][i]);
  }
  cout << q << endl;
}
