#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 1;
int dp[maxn][maxn];
pair<pair<int, int>, pair<pair<int, int>, char> > v[maxn][maxn];
string op[4] = {"", "INSERT ", "DELETE ", "REPLACE "};
int n, m;
void print(int i, int j) {
  if (i == 0 && j == 0) return;
  print(v[i][j].first.first, v[i][j].first.second);
  if (v[i][j].second.first.first != 0)
    cout << op[v[i][j].second.first.first] << v[i][j].second.first.second << ' '
         << v[i][j].second.second << endl;
}
int main() {
  string s, t;
  cin >> s >> t;
  n = int(s.size());
  m = int(t.size());
  dp[0][0] = 0;
  for (int i = 1; i <= m; i++) {
    dp[0][i] = i;
    v[0][i].first = make_pair(0, i - 1);
    v[0][i].second = make_pair(make_pair(1, i), t[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = i;
    v[i][0].first = make_pair(i - 1, 0);
    v[i][0].second = make_pair(make_pair(2, 1), ' ');
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
        v[i][j].first = make_pair(i - 1, j - 1);
        v[i][j].second = make_pair(make_pair(0, 0), ' ');
      } else {
        pair<int, pair<int, int> > arr[3] = {
            make_pair(dp[i - 1][j], make_pair(i - 1, j)),
            make_pair(dp[i][j - 1], make_pair(i, j - 1)),
            make_pair(dp[i - 1][j - 1], make_pair(i - 1, j - 1))};
        sort(arr, arr + 3);
        int k = arr[0].second.first, l = arr[0].second.second;
        dp[i][j] = dp[k][l] + 1;
        v[i][j].first = make_pair(k, l);
        if (k == i - 1 && l == j)
          v[i][j].second = make_pair(make_pair(2, j + 1), ' ');
        else if (k == i && l == j - 1)
          v[i][j].second = make_pair(make_pair(1, j), t[j - 1]);
        else
          v[i][j].second = make_pair(make_pair(3, j), t[j - 1]);
      }
    }
  cout << dp[n][m] << endl;
  print(n, m);
  return 0;
}
