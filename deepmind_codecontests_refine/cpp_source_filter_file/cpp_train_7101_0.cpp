#include <bits/stdc++.h>
using namespace std;
const long long lt = 100005;
long long mod = 1000000007;
long long val(char c) { return (long long)c - (long long)'a'; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  long long k, i;
  cin >> s >> k;
  long long n = (long long)(s).size();
  if (k > (n * (n + 1)) / 2) {
    cout << "No such line\n";
    return 0;
  }
  string ans;
  vector<long long> x[26];
  for (i = 0; i < n; i++) x[val(s[i])].push_back(i);
  while (true) {
    long long j;
    long long cnt = 0;
    long long tmp = 0;
    for (i = 0; i < 26; i++) {
      tmp = cnt;
      for (j = 0; j < (long long)(x[i]).size(); j++) cnt += (n - x[i][j]);
      if (cnt >= k) break;
    }
    k -= tmp;
    ans.push_back('a' + (char)i);
    if (k <= (long long)(x[i]).size())
      break;
    else
      k -= (long long)(x[i]).size();
    vector<long long> xx[26];
    for (j = 0; j < (long long)(x[i]).size(); j++)
      if (x[i][j] + 1 < n) xx[val(s[x[i][j] + 1])].push_back(x[i][j] + 1);
    for (i = 0; i < 26; i++) x[i] = xx[i];
  }
  cout << ans << endl;
  return 0;
}
