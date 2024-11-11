#include <bits/stdc++.h>
using namespace std;
const int N = 402;
const int MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
int stop;
string s, t;
bool dp[N][N][N], vp[N][N][N];
bool fun(int pos1, int pos2, int pos3) {
  if (pos3 == s.size()) {
    return pos1 == stop && pos2 == t.size();
  }
  if (pos1 == stop && pos2 == t.size()) {
    return 1;
  }
  bool &tmp = dp[pos1][pos2][pos3];
  bool &vmp = vp[pos1][pos2][pos3];
  if (vmp) {
    return tmp;
  }
  tmp = 0, vmp = 1;
  if (pos1 < stop && t[pos1] == s[pos3]) {
    tmp |= fun(pos1 + 1, pos2, pos3 + 1);
  }
  if (pos2 < t.size() && t[pos2] == s[pos3]) {
    tmp |= fun(pos1, pos2 + 1, pos3 + 1);
  }
  tmp |= fun(pos1, pos2, pos3 + 1);
  return tmp;
}
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    bool ok = 0;
    cin >> s >> t;
    memset(vp, 0, sizeof vp);
    for (int i = 0; i < t.size() - 1; i++) {
      stop = i + 1;
      if (fun(0, i + 1, 0)) {
        ok = 1;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
