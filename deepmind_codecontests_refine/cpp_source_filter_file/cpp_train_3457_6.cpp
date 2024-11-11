#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589;
const long long int zero = 0;
long long int mod = 1000000007;
const long long int inf = 1e9;
const long long int inff = 9000000000000000000;
char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char al[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
               'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char capital[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i += 1) {
      cin >> a[i] >> b[i] >> c[i];
    }
    pair<int, int> portals[m];
    for (int i = 0; i < m; i += 1) {
      cin >> portals[i].first >> portals[i].second;
    }
    sort(portals, portals + m);
    set<int> s;
    vector<int> adj[n];
    for (int i = m - 1; i >= 0; i -= 1) {
      if (!s.count(portals[i].second)) {
        s.insert(portals[i].second);
        adj[portals[i].first - 1].push_back(portals[i].second);
      }
    }
    for (int i = 1; i < n + 1; i += 1) {
      if (!s.count(i)) {
        adj[i - 1].push_back(i);
      }
    }
    int curr = k;
    for (int i = 0; i < n; i += 1) {
      if (a[i] > curr) {
        cout << -1;
        return 0;
      }
      curr += b[i];
    }
    int dp[n + 1][5000 + 1];
    for (int i = 0; i < n + 1; i += 1) {
      for (int j = 0; j < 5000 + 1; j += 1) {
        dp[i][j] = -1;
      }
    }
    dp[0][k] = 0;
    for (int i = 1; i < n + 1; i += 1) {
      vector<int> add;
      for (int j = 0; j < a[i - 1]; j += 1) {
        dp[i - 1][j] = -1;
      }
      if (adj[i - 1].empty()) {
        for (int j = 0; j < 5000 + 1; j += 1) {
          if (dp[i - 1][j] != -1) dp[i][j + b[i - 1]] = dp[i - 1][j];
        }
        continue;
      }
      for (int j = 0; j < adj[i - 1].size(); j += 1) {
        add.push_back(c[adj[i - 1][j] - 1]);
      }
      sort(add.begin(), add.end());
      int sum = 0;
      for (int j = add.size() - 1; j >= 0; j -= 1) {
        sum += add[j];
        add[j] = sum;
      }
      reverse(add.begin(), add.end());
      for (int j = 0; j < 5000 + 1; j += 1) {
        if (dp[i - 1][j] != -1) {
          for (int ii = 1; ii < add.size() + 1; ii += 1) {
            if (j + b[i - 1] - ii > 5000 && j + b[i - 1] - ii >= 0) {
              continue;
            }
            dp[i][j + b[i - 1] - ii] =
                max(dp[i][j + b[i - 1] - ii], dp[i - 1][j] + add[ii - 1]);
          }
          dp[i][j + b[i - 1]] = max(dp[i][j + b[i - 1]], dp[i - 1][j]);
        }
      }
    }
    int ans = 0;
    for (int j = 0; j < 5000 + 1; j += 1) {
      ans = max(ans, dp[n][j]);
    }
    cout << ans;
  }
}
