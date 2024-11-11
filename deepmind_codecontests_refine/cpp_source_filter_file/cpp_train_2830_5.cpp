#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long MAXN = 0x7fffffff;
void file() {}
void pr(bool num) { cout << (num == 1 ? "YES" : "NO") << "\n"; }
const long long N = 2e5 + 5;
long long dp[2][N];
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  file();
  long long n;
  while (cin >> n) {
    string str1, str2;
    cin >> str1 >> str2;
    vector<pair<long long, long long> > vec;
    long long flag = 0;
    long long index;
    vector<long long> s, t;
    for (long long i = 0; i < n; i++) {
      if (str1[i] == 'a' && str2[i] == 'b') s.push_back(i);
      if (str1[i] == 'b' && str2[i] == 'a') t.push_back(i);
    }
    long long len1 = s.size(), len2 = t.size();
    for (long long i = 0; i < len1; i += 2)
      if (i + 1 < len1) vec.push_back(make_pair(s[i] + 1, s[i + 1] + 1));
    for (long long i = 0; i < len2; i += 2)
      if (i + 1 < len2) vec.push_back(make_pair(t[i] + 1, t[i + 1] + 1));
    if ((len1 % 2 + len2 % 2) % 2 == 0) {
      if (len1 % 2 && len2 % 2) {
        vec.push_back(make_pair(s[len1 - 1] + 1, s[len1 - 1] + 1));
        vec.push_back(make_pair(s[len1 - 1] + 1, t[len1 - 1] + 1));
      }
      cout << vec.size() << "\n";
      long long len = vec.size();
      for (long long i = 0; i < len; i++)
        cout << vec[i].first << " " << vec[i].second << "\n";
    } else
      cout << -1 << "\n";
  }
  return 0;
}
