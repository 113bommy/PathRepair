#include <bits/stdc++.h>
using namespace std;
string revers(string& s) {
  string c = s;
  reverse(c.begin(), c.end());
  return c;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  long long ctt = 0, pr, se, c;
  long long mx = 0;
  long long zero = 0;
  cin >> n >> k;
  map<string, vector<long long>> m;
  string s, rev;
  for (int i = 0; i < n; ++i) {
    cin >> s >> c;
    m[s].push_back(c);
  }
  for (auto key : m) {
    sort(key.second.begin(), key.second.end());
  }
  for (auto key : m) {
    s = key.first;
    rev = revers(s);
    if (s == rev) {
      while (m[s].size() > 1) {
        pr = m[s].back();
        m[s].pop_back();
        se = m[s].back();
        m[s].pop_back();
        if (pr > 0 && se < 0) mx = max(mx, pr - max(pr + se, zero));
        ctt += max(pr + se, zero);
      }
      if (m[s].size() > 0) {
        pr = m[s].back();
        m[s].pop_back();
        mx = max(mx, pr);
      }
    } else {
      while (m[s].size() > 0 && m[rev].size() > 0) {
        pr = m[s].back();
        m[s].pop_back();
        se = m[rev].back();
        m[rev].pop_back();
        ctt += max(pr + se, zero);
      }
    }
    m[s].clear();
    m[rev].clear();
  }
  cout << ctt + mx;
  return 0;
}
