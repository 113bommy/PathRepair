#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
const double EPS = 1e-10;
const double PI = acos(-1.0);
long long dp[10001][2] = {1};
const int M = 1000000007;
int main() {
  string start, end;
  cin >> start >> end;
  int k;
  cin >> k;
  string start2(start);
  vector<int> indexes;
  for (int i = (0); i < (start2.size()); ++i) {
    if (end == start2) {
      indexes.push_back(i);
    }
    char c = start2[0];
    start2.erase(start2.begin());
    start2 += c;
  }
  if (indexes.empty()) {
    cout << 0;
    return 0;
  }
  int n = start.size();
  for (int i = (0); i < (k + 1); ++i) {
    dp[i][0] += dp[i - 1][1] * (n - 1);
    dp[i][0] %= M;
    dp[i][1] += dp[i - 1][0] + dp[i - 1][1] * (n - 2);
    dp[i][1] %= M;
  }
  long long ret = 0;
  for (vector<int>::iterator it = (indexes).begin(); it != (indexes).end();
       ++it) {
    ret += dp[k][*it == 0 ? 0 : 1];
    ret %= M;
  }
  cout << ret;
}
