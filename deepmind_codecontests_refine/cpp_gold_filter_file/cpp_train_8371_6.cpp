#include <bits/stdc++.h>
using namespace std;
long long a[1000010], d[1000010];
long long b[100010], c[1010][1010];
long long mn = 1e18, mx = -1e18, ans, cnt, sm = 1, n, m, cur;
bool ok, okk, u[1000010], uu[310][310], uk[1000010];
char ck[510][510], ch[100010];
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
vector<long long> g[900010];
int main() {
  std::ios::sync_with_stdio(false);
  string s;
  cin >> s;
  s += '#';
  cnt = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1]) {
      if (cnt % 2 == 1) {
        cnt = 1;
      } else {
        ans++;
        cnt = 1;
      }
    } else {
      cnt++;
    }
  }
  cout << ans;
  return 0;
}
