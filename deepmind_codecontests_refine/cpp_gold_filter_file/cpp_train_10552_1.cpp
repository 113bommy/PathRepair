#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
const double EPS = 1e-5;
const long long mod = ((long long)1e18) - 131;
int n, m, ans = 0;
set<string> h;
string s;
int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    for (int j = i; j < s.length(); j++) {
      if (h.count(s.substr(i, j - i + 1)))
        ans = max(ans, j - i + 1);
      else
        h.insert(s.substr(i, j - i + 1));
    }
  printf("%d", ans);
  return 0;
}
