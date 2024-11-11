#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const double PI = 3.14159265358979323846;
int z[400005];
void search(vector<pair<long long, char>> s, vector<pair<long long, char>> t) {
  t.push_back({1, '_'});
  t.insert(t.end(), s.begin(), s.end());
  z[0] = t.size();
  int l = 0, r = 0;
  for (int i = 1; i < t.size(); ++i) {
    if (i > r) {
      l = r = i;
      while (r < t.size() && t[r] == t[r - l]) {
        ++r;
      }
      z[i] = r - l;
      --r;
    } else {
      int k = i - l;
      if (z[k] < r - i + 1) {
        z[i] = z[k];
      } else {
        l = i;
        while (r < t.size() && t[r] == t[r - l]) {
          ++r;
        }
        z[i] = r - l;
        --r;
      }
    }
  }
}
void get_input(vector<pair<long long, char>> &s, int n) {
  char p = '/';
  int len = 0;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    char c = str.back();
    if (c != p && p != '/') {
      s.push_back({len, p});
      len = 0;
    }
    p = c;
    len += atoi(str.substr(0, str.size() - 2).c_str());
  }
  s.push_back({len, p});
}
int main() {
  if (0) {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
  int n, m;
  vector<pair<long long, char>> s, t;
  cin >> n >> m;
  get_input(s, n);
  get_input(t, m);
  n = s.size();
  m = t.size();
  if (m == 1) {
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i].second == t[0].second) {
        ans += max(s[i].first - t[0].first + 1, 0ll);
      }
    }
    cout << ans << endl;
  } else {
    search(s, vector<pair<long long, char>>(t.begin() + 1, t.end() - 1));
    long long ans = 0;
    for (int i = 1; i <= n - m + 1; ++i) {
      if (z[m - 1 + i] == m - 2) {
        if (t[0].first > 0 && t[0].first <= s[i - 1].first &&
            t[0].second == s[i - 1].second) {
          if (t[m - 1].first > 0 && t[m - 1].first <= s[i + m - 2].first &&
              t[m - 1].second == s[i + m - 2].second) {
            ++ans;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
