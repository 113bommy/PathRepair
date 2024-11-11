#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<pair<long long, long long> > v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++)
    for (int j = 1; 2 * j < min(n - i, 9); j++)
      if (s[i] == s[i + j] && s[i] == s[i + 2 * j]) {
        long long x = i;
        long long y = i + 2 * j;
        if (!v.empty() && v.back().second >= y) v.pop_back();
        v.push_back(make_pair(x, y));
        break;
      }
  long long lastx = -1;
  long long ans = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    long long currx = v[i].first;
    long long curry = v[i].second;
    ans += (currx - lastx) * (n - curry);
    lastx = currx;
  }
  cout << ans;
  return 0;
}
