#include <bits/stdc++.h>
using namespace std;
int c[4100];
long long s[4100];
vector<long long> g;
string str;
int main() {
  long long a;
  cin >> a;
  cin >> str;
  int len = str.length();
  for (int i = 0; str[i]; i++) c[i + 1] = str[i] - '0';
  for (int i = 1; i <= len; i++) {
    s[i] = s[i - 1] + (long long)c[i];
  }
  for (int i = 0; i <= len; i++)
    for (int j = i + 1; j <= len; j++) g.push_back(s[j] - s[i]);
  sort(g.begin(), g.end());
  int sz = g.size(), sz1;
  sz1 = upper_bound(g.begin(), g.end(), 0) - lower_bound(g.begin(), g.end(), 0);
  long long ans = 0;
  for (int i = 0; i < sz; i++) {
    if (g[i] == 0) {
      if (a == 0) ans += sz;
      continue;
    }
    if (a % g[i] == 0 &&
        *lower_bound(g.begin(), g.end(), a / g[i]) == a / g[i]) {
      if (a == 0) {
        ans += sz1;
        continue;
      }
      ans += upper_bound(g.begin(), g.end(), a / g[i]) -
             lower_bound(g.begin(), g.end(), a / g[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
