#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
inline int readint() {
  int x = 0, s = 1, c = getchar();
  while (c <= 32) c = getchar();
  if (c == '-') s = -1, c = getchar();
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  return x * s;
}
const int maxn = 1e4 + 5;
string s;
string Test[3];
string Get[3];
int main() {
  cin >> s;
  int n = s.size();
  for (int i = 0; i <= n - 1; i++) {
    Test[0] += char('a' + i % 26);
    Test[1] += char('a' + (i / 26) % 26);
    Test[2] += char('a' + (i / 26 / 26) % 26);
  }
  for (int i = 0; i <= 2; i++) {
    cout << "? " << Test[i] << endl;
    fflush(stdout);
    cin >> Get[i];
  }
  vector<int> v;
  for (int i = 0; i <= n - 1; i++) {
    v.push_back((Get[0][i] - 'a') + (Get[1][i] - 'a') * 26 +
                (Get[2][i] - 'a') * 26 * 26);
  }
  string ans(n, 'a');
  for (int i = 0; i <= n - 1; i++) {
    ans[v[i]] = s[i];
  }
  cout << "! " << ans << endl;
  return 0;
}
