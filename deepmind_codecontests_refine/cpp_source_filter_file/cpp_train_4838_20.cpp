#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7;
const long long maxN = 1e6 + 5;
const long long MOD = 1e9 + 7;
string tmp1, tmp2;
int P[maxN], n, m;
int dp[maxN], sum[maxN];
vector<char> s, t;
vector<int> ind;
int add(int a, int b) {
  int z = a + b;
  if (z >= MOD) z -= MOD;
  return z;
}
vector<char> shift(string &s) {
  vector<char> tmp((int)s.size() + 1);
  for (int i = (0); i <= (((int)s.size()) - 1); ++i) {
    tmp[i + 1] = s[i];
  }
  return tmp;
}
void KMP() {
  P[1] = 0;
  int k = 0;
  for (int i = (2); i <= (m); ++i) {
    while (k != 0 && t[k + 1] != t[i]) k = P[k];
    if (t[k + 1] == t[i]) k++;
    P[i] = k;
  }
  for (int i = (1); i <= (n); ++i) {
    while (k != 0 && t[k + 1] != s[i]) k = P[k];
    if (t[k + 1] == s[i]) k++;
    if (k == (int)t.size() - 1) {
      ind.push_back(i - m + 1);
      k = P[k];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> tmp1;
  cin >> tmp2;
  n = (int)tmp1.size();
  m = (int)tmp2.size();
  s = shift(tmp1);
  t = shift(tmp2);
  KMP();
  reverse(ind.begin(), ind.end());
  dp[0] = 0;
  sum[0] = 1;
  for (int i = (1); i <= ((n)); ++i) {
    dp[i] = dp[i - 1];
    auto it = lower_bound(ind.begin(), ind.end(), i - m + 1, greater<int>());
    if (it != ind.end()) {
      dp[i] = add(dp[i], sum[*it - 1]);
    }
    sum[i] = add(sum[i - 1], dp[i]);
    sum[i] = add(sum[i], 1);
  }
  cout << dp[n] << endl;
  return 0;
}
