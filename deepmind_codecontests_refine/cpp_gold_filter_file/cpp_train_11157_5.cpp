#include <bits/stdc++.h>
using namespace std;
long long check(string &s, long long i, long long j, string &s1, string &s2,
                string &s3) {
  long long a = 0, b = 0, c = 0, p = 0;
  for (long long first = i; first < j; first++) {
    if (s[first] != s1[p]) a++;
    if (s[first] != s2[p]) b++;
    if (s[first] != s3[p]) c++;
    p++;
  }
  return min(a, min(b, c));
}
void solve() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string s1 = "", s2 = "", s3 = "";
  long long flag = 1;
  for (long long i = 0; i < k; i++) {
    if (flag == 1) {
      s1 += "R";
      s2 += "G";
      s3 += "B";
      flag = 2;
    } else if (flag == 2) {
      s1 += "G";
      s2 += "B";
      s3 += "R";
      flag = 3;
    } else if (flag == 3) {
      s1 += "B";
      s2 += "R";
      s3 += "G";
      flag = 1;
    }
  }
  long long ans = INT_MAX;
  for (long long i = 0; i < n - k + 1; i++) {
    ans = min(ans, check(s, i, i + k, s1, s2, s3));
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
