#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 1e6;
const long long Max = 1e3;
const long long Mod = 1e9 + 7;
string s;
long long dp[Maxn];
vector<long long> V;
long long f(long long a, long long b) {
  if (a > b - 1) return 0;
  if (a == b - 1) return (s[a] - '0');
  long long sum = 1, point = -1;
  dp[a] = (s[a] - '0');
  if (s[a + 1] == '+') {
    sum = 1;
    dp[a + 2] = dp[a] + (s[a + 2] - '0');
  } else {
    point = 2;
    sum = (s[a] - '0') * (s[a + 2] - '0');
    dp[a + 2] = sum;
  }
  for (long long i = a + 3; i < b; i += 2) {
    if (s[i] == '+') {
      point = -1;
      sum = 1;
      dp[i + 1] = dp[i - 1] + (s[i + 1] - '0');
    } else {
      if (point == -1) {
        point = 2;
        sum = (s[i - 1] - '0') * (s[i + 1] - '0');
        if (i >= 3)
          dp[i + 1] = sum + dp[i - 3];
        else
          dp[i + 1] = sum;
      } else {
        point++;
        sum *= (s[i + 1] - '0');
        if ((i - 2 * point + 1) >= a)
          dp[i + 1] = sum + dp[i - (2 * point) + 1];
        else
          dp[i + 1] = sum;
      }
    }
  }
  return dp[b - 1];
}
pair<long long, long long> g(long long a) {
  if (a == -1) return make_pair(0, 1);
  long long point, sum = 1;
  for (long long i = a; i > 0; i -= 2) {
    if (s[i] != '*') break;
    sum *= s[i - 1] - '0';
    point = i;
  }
  return make_pair(f(0, point - 2), sum);
}
pair<long long, long long> l(long long b) {
  if (b == s.size()) return make_pair(0, 1);
  long long point, sum = 1;
  for (long long i = b; i < s.size(); i += 2) {
    if (s[i] != '*') break;
    sum *= s[i + 1] - '0';
    point = i;
  }
  return make_pair(f(point + 3, s.size()), sum);
}
int main() {
  cin >> s;
  long long ans = 0;
  V.push_back(-1);
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '*') V.push_back(i);
  }
  V.push_back(s.size());
  for (long long i = 0; i < V.size(); i++)
    for (long long j = i + 1; j < V.size(); j++) {
      pair<long long, long long> tmp = g(V[i]);
      pair<long long, long long> td = l(V[j]);
      long long sum =
          (tmp.second * td.second * f(V[i] + 1, V[j])) + tmp.first + td.first;
      ans = max(ans, sum);
    }
  cout << ans << endl;
  return 0;
}
