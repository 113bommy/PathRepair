#include <bits/stdc++.h>
const int INF = (int)(1e9);
const long long INFLL = (long long)(1e18);
const double EPS = 1e-13;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  sort((s).begin(), (s).end());
  reverse((s).begin(), (s).end());
  string ans = s.substr(0, 1);
  int i = 1;
  while (i <= s.size()) {
    string pal = s.substr(0, i);
    reverse((pal).begin(), (pal).end());
    if (s.substr(0, i) != pal) break;
    if (s.substr(0, i) > ans) ans = s.substr(0, i);
    i++;
  }
  cout << ans << endl;
}
