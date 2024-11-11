#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long MAXN = 2e3 + 69;
const long long MOD = 1e9 + 7;
const long long BASE = 11;
int n, arr[MAXN][MAXN];
pair<long long, pair<int, int>> res[2], ans[MAXN * MAXN];
map<int, long long> diag[2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j], diag[0][i - j] += arr[i][j],
          diag[1][i + j] += arr[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ans[i * n + j].first = diag[0][i - j] + diag[1][i + j] - arr[i][j],
                  ans[i * n + j].second.first = i + 1,
                  ans[i * n + j].second.second = j + 1;
  for (int i = 0; i < n * n; i++)
    if (ans[i].first >=
        res[(ans[i].second.first + ans[i].second.second) % 2].first) {
      res[(ans[i].second.first + ans[i].second.second) % 2].first =
          ans[i].first;
      res[(ans[i].second.first + ans[i].second.second) % 2].second.first =
          ans[i].second.first;
      res[(ans[i].second.first + ans[i].second.second) % 2].second.second =
          ans[i].second.second;
    }
  cout << res[0].first + res[1].first << "\n";
  for (int i = 0; i < 2; i++)
    cout << res[i].second.first << " " << res[i].second.second << " ";
  return cout << '\n', 0;
}
