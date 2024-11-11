#include <bits/stdc++.h>
using namespace std;
inline long double min(long double a, long double b) {
  if (a < b) return a;
  return b;
}
inline long double max(long double a, long double b) {
  if (a < b) return b;
  return a;
}
vector<string> split(string s, string c) {
  unsigned long pos2 = s.find(c);
  unsigned long pos1 = 0;
  vector<string> res;
  while (pos2 != s.size()) {
    res.push_back(s.substr(pos1, pos2 - pos1));
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if (pos1 != s.size()) res.push_back(s.substr(pos1));
  return res;
}
int n;
int arr[100100];
int dp[100100][2];
int solve() {
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][arr[0]] = 1;
  for (int(i) = (1); (i) < (n); ++(i)) {
    if (arr[i] == 0) {
      dp[i][1] = dp[i - 1][1];
      dp[i][0] = dp[i - 1][1] + 1;
    } else {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][0] + 1;
    }
  }
  int res = max(dp[n - 1][0], dp[n - 1][1]);
  return min(n, res + 2);
  int len = 1;
  int count = 1;
  for (int(i) = (1); (i) < (n); ++(i)) {
    if (arr[i] == arr[i - 1])
      count++;
    else {
      len = max(len, count);
      count = 1;
    }
  }
  len = max(len, count);
  if (len >= 3)
    return res + 2;
  else if (len == 2)
    return res + 1;
  return res;
}
string s;
int main() {
  cin >> n;
  cin >> s;
  for (int(i) = (0); (i) < (n); ++(i)) arr[i] = s[i] - '0';
  cout << solve() << endl;
  return 0;
}
