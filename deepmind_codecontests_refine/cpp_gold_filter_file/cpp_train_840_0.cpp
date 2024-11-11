#include <bits/stdc++.h>
using namespace std;
long long gcd(long long first, long long second) {
  return !second ? first : gcd(second, first % second);
}
long long x, y, dp[705][705][5];
bool z[705][705];
deque<long long> q;
bool rec(long long s, long long ss, bool n) {
  if (s > ss) {
    return 1;
  }
  long long &re = dp[s][ss][n];
  if (re != -1) {
    return re;
  }
  long long ans;
  if (n) {
    ans = s - 1;
  } else {
    ans = ss + 1;
  }
  for (int i = s; i < ss + 1; i++) {
    if (z[ans][i] && rec(s, i - 1, 0) && rec(i + 1, ss, 1)) {
      return re = 1;
    }
  }
  return re = 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> x;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < x; i++) {
    cin >> y;
    q.push_back(y);
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      z[i][j] = (gcd(q[i], q[j]) > 1);
    }
  }
  for (int i = 0; i < x; i++) {
    if (rec(0, i - 1, 0) && rec(i + 1, x - 1, 1)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
