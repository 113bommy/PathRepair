#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const int INF = 1e9;
int dp[MAX];
string add(int v, string s) {
  int i = s.size() - 1;
  int carry = v;
  while (carry != 0 && i >= 0) {
    int d = s[i] - '0';
    d += carry;
    carry = d / 10;
    d %= 10;
    s[i] = '0' + d;
    i--;
  }
  if (carry != 0) {
    string ret = '1' + s;
    return ret;
  } else
    return s;
}
int main() {
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  int pos;
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') {
      pos = i;
      break;
    }
  }
  if (s[n - 1] - '0' >= 5)
    dp[n - 1] = 0;
  else
    dp[n - 1] = INF;
  for (int i = n - 2; i >= pos; i--) {
    if (s[i + 1] - '0' >= 5) {
      dp[i] = 1;
    } else if (s[i + 1] - '0' == 4) {
      dp[i] = 1 + dp[i + 1];
    } else {
      dp[i] = INF;
    }
  }
  int p = -1;
  for (int i = pos; i < n; i++) {
    if (dp[i] <= t) {
      p = i;
      break;
    }
  }
  if (p == -1) {
    cout << s;
    return 0;
  }
  string inte = "";
  for (int i = 0; i < pos; i++) inte += s[i];
  if (p == pos) {
    inte = add(1, inte);
    cout << inte;
  } else {
    string dec = "";
    for (int i = pos + 1; i < p; i++) dec += s[i];
    dec += (s[p] + 1);
    cout << inte << "." << dec;
  }
  return 0;
}
