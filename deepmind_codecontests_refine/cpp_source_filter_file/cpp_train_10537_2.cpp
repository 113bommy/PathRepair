#include <bits/stdc++.h>
using namespace std;
inline bool invowel(char ch) {
  ch = tolower(ch);
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
inline bool isprime(int n) {
  if (n < 2 || (n % 2 == 0 && n != 2)) return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while (t--) {
    string from, to;
    int cnt = 0, pos = 0, i, flag = 0, j;
    cin >> from >> to;
    int dp[int(from.size())][26];
    map<char, int> used;
    for (i = 0; i < from.size(); i++) {
      for (j = 0; j < 26; j++) {
        dp[i][j] = -1;
      }
    }
    for (auto it : from) {
      used[it]++;
    }
    for (auto it : to) {
      if (!used.count(it)) {
        flag++;
        break;
      }
    }
    if (flag) {
      cout << -1 << '\n';
      continue;
    }
    for (i = from.size() - 1; i >= 0; i--) {
      if (i != from.size() - 1) {
        for (j = 0; j < 26; j++) {
          dp[i][j] = dp[i + 1][j];
        }
      }
      int p = int(from[i] - 'a');
      dp[i][p] = i;
    }
    for (i = 0; i < to.size(); i++) {
      char it = to[i];
      int p = int(it - 'a');
      if (dp[pos][p] != -1) {
        pos = dp[pos][p] + 1;
        if (pos == from.size()) {
          cnt++;
          pos = 0;
        }
        if (i + 1 != from.size()) {
          int h = (int)to[i + 1] - 'a';
          if (dp[pos][h] == -1) i--;
        }
      } else {
        pos = 0;
        cnt++;
      }
    }
    if (pos) cnt++;
    cout << cnt << '\n';
  }
  return 0;
}
