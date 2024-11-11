#include <bits/stdc++.h>
using namespace std;
int compare(string s, string s1) {
  int ans = 0;
  for (int i = 0; i < 7; i++) {
    if (s[i] == '1' && s1[i] == '0') {
      ans++;
    } else if (s[i] == '0' && s1[i] == '1') {
      return -1;
    }
  }
  return ans;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int a, b, t, c, d, n, k;
  cin >> n >> k;
  string s[10] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                  "1101011", "1101111", "1010010", "1111111", "1111011"};
  string str;
  int dist[n + 1][10];
  for (int i = 1; i <= n; i++) {
    cin >> str;
    for (int j = 0; j < 10; j++) {
      dist[i][j] = compare(s[j], str);
    }
  }
  int dp[n + 1][k + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = 0;
    }
  }
  dp[n + 1][0] = 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= k; j++) {
      if (dp[i + 1][j] == 1) {
        for (int d = 0; d < 10; d++) {
          if (dist[i][d] + j <= k && dist[i][d] != -1) {
            dp[i][j + dist[i][d]] = 1;
          }
        }
      }
    }
  }
  if (dp[1][k] == 0) {
    cout << -1;
    return 0;
  } else {
    for (int i = 1; i <= n; i++) {
      for (int d = 9; d >= 0; d--) {
        if (dist[i][d] != -1 && dp[i + 1][k - dist[i][d]] == 1 &&
            k >= dist[i][d]) {
          cout << d;
          k -= dist[i][d];
          break;
        }
      }
    }
  }
  return 0;
}
