#include <bits/stdc++.h>
using namespace std;
inline bool isvowel(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u')
    return 1;
  return 0;
}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;
const int M = 22;
const int pri = 997;
const int Magic = 2101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, k;
string s, t;
int cnt[202];
string shift(string s, int x) {
  string rev = "";
  while (x--) {
    rev += s.back();
    s.pop_back();
  }
  return rev + s;
}
int main() {
  cin >> n >> s >> t;
  for (auto c : s) cnt[c]++;
  for (auto c : t) cnt[c]--;
  for (int i = 'a'; i < 'z'; i++)
    if (cnt[i] != 0) {
      cout << -1;
      return 0;
    }
  vector<int> ans;
  int l = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = l; j < n; j++) {
      if (s[j] == t[i]) {
        l++;
        s = shift(s, n);
        s = shift(s, j);
        s = shift(s, 1);
        ans.push_back(n);
        if (j) ans.push_back(j);
        ans.push_back(1);
        break;
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto e : ans) cout << e << ' ';
  return 0;
}
