#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = (int)1e6 + 7, mod = 1000000007, M = 2e9;
int n, c[13], t, ans[13], cnt, a, mx;
bool f[13], z;
string s[1007];
bool cmp(pair<char, int> a, pair<char, int> b) { return a.second > b.second; }
int main() {
  memset(ans, -1, sizeof ans);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    t = 1;
    f[s[i][0] - 'a'] = 1;
    for (int j = 1; j < s[i].size(); j++) t *= 10;
    for (int j = 0; j < s[i].size(); j++) {
      c[s[i][j] - 'a'] += t;
      t /= 10;
    }
  }
  t = 0;
  for (int i = 1; i <= 10; i++) {
    int j = 0;
    while (ans[j] > -1) j++;
    mx = j;
    while (j < 10) {
      if (ans[j] == -1 && c[j] > c[mx]) mx = j;
      j++;
    }
    if (!z && !f[mx])
      i--, z = 1, ans[mx] = 0;
    else
      ans[mx] = i;
  }
  for (int i = 0; i < n; i++) {
    a = 0;
    for (int j : s[i]) {
      a *= 10;
      a += ans[j - 'a'];
    }
    cnt += a;
  }
  cout << cnt;
  return 0;
}
