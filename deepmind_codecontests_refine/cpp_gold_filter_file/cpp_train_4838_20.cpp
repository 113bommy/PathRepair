#include <bits/stdc++.h>
using namespace std;
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
long long prefixsum[1234567];
long long sum[1234567];
long long mas[1234567];
long long dp[1234567];
long long prostosum[1234567];
char sss[1234567];
char ttt[1234567];
int main() {
  ios_base::sync_with_stdio(0);
  string s, t;
  gets(sss);
  gets(ttt);
  for (int i = 0; sss[i]; ++i) s += sss[i];
  for (int i = 0; ttt[i]; ++i) t += ttt[i];
  string ss = t + "#" + s;
  for (int i = 0; i < s.size(); ++i) mas[i] = -1;
  vector<int> vc = z_function(ss);
  vector<int> nachal;
  for (int i = 0; i < s.size(); ++i)
    if (vc[i + t.size() + 1] >= t.size()) nachal.push_back(i);
  int cursum = 0;
  int ii = 0;
  if (nachal.size() == 0) {
    cout << 0;
    return 0;
  }
  for (int i = t.size() - 1; i < s.size(); ++i) {
    if (ii + 1 < nachal.size() && nachal[ii + 1] + t.size() - 1 <= i) {
      mas[i] = nachal[ii + 1];
      ++ii;
    } else {
      if (nachal[ii] + t.size() - 1 <= i)
        mas[i] = nachal[ii];
      else
        mas[i] = -1;
    }
  }
  for (int i = nachal[0] + t.size() - 1; i < s.size(); ++i) {
    sum[i] = prefixsum[mas[i] - 1] + mas[i] + 1;
    if (sum[i] > 1000000007) sum[i] -= 1000000007;
    if (i == 0) {
      prostosum[i] = sum[i];
      if (prostosum[i] > 1000000007) prostosum[i] -= 1000000007;
      prefixsum[i] = sum[i];
      if (prefixsum[i] > 1000000007) prefixsum[i] -= 1000000007;
    } else {
      prostosum[i] = prostosum[i - 1] + sum[i];
      if (prostosum[i] > 1000000007) prostosum[i] -= 1000000007;
      prefixsum[i] = sum[i] + prefixsum[i - 1] + prostosum[i - 1];
      if (prefixsum[i] > 1000000007) prefixsum[i] -= 1000000007;
      if (prefixsum[i] > 1000000007) prefixsum[i] -= 1000000007;
    }
  }
  long long ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    ans += sum[i];
    if (ans >= 1000000007) {
      ans -= 1000000007;
    }
  }
  cout << ans;
  return 0;
}
