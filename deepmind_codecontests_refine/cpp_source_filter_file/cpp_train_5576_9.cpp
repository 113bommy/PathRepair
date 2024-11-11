#include <bits/stdc++.h>
const int inf = (int)1e9;
const int mod = 1e9 + 7;
using namespace std;
int n, t;
string s;
long long dp[300011];
char add(char x) {
  if (x < '9') {
    return char((int)x + 1);
  } else
    return 't';
}
void ans(int id) {
  id--;
  if (s[id] == '.') id--;
  s[id] = add(s[id]);
  int b = 0;
  for (int i = id; i >= 0; i--) {
    if (s[i] == '.') continue;
    if (b == 1) {
      s[i] = add(s[i]);
    }
    b = 0;
    if (s[i] == 't') {
      b = 1;
    }
  }
  if (s[0] == 't') {
    cout << '1';
  }
  for (int i = 0; i <= id; i++) {
    if (s[i] == 't')
      cout << '0';
    else
      cout << s[i];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> t >> s;
  dp[n] = inf;
  bool f = 0;
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = 2 * inf;
    if (s[i] == '.') {
      break;
    }
    if (s[i] >= '5') {
      dp[i] = 1;
    } else if (s[i] < '4') {
      dp[i] = inf;
    } else if (s[i] == '4') {
      dp[i] = dp[i + 1 + f] + 1;
    }
    if (f) break;
  }
  int id = n;
  for (int i = 0; i < n; i++) {
    if (dp[i] > 0 && dp[i] <= t) {
      id = i;
      break;
    }
  }
  if (id == n) {
    cout << s;
    return 0;
  }
  ans(id);
  return 0;
}
