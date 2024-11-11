#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXM = 100005;
int a[MAXN + 1], b[MAXM + 1], fail[MAXM + 1];
void makefail(string B, int m) {
  fail[0] = -1;
  for (int i = 1, j = -1; i < m; i++) {
    while (j >= 0 && B[j + 1] != B[i]) j = fail[j];
    if (B[j + 1] == B[i]) j++;
    fail[i] = j;
  };
}
string s1, s2, m1, m2;
int L1, L2;
map<string, bool> vis;
int main() {
  cin >> s1 >> s2;
  int l1 = s1.length();
  int l2 = s2.length();
  makefail(s1, l1);
  int ind;
  ind = fail[l1 - 1];
  L1 = l1 - 1 - ind;
  if ((l1 % L1) == 0) {
    m1 = s1.substr(0, L1);
  } else {
    L1 = l1;
    m1 = s1;
  }
  int cc = l1 / L1;
  vis.clear();
  string tt = "";
  for (int i = 1; i <= cc; i++) {
    tt += m1;
    if ((cc % i)) continue;
    vis[tt] = true;
  }
  makefail(s2, l2);
  ind = fail[l2 - 1];
  L2 = l2 - 1 - ind;
  if ((l2 % L2) == 0) {
    m2 = s2.substr(0, L2);
  } else {
    L2 = l2;
    m2 = s2;
  }
  cc = l2 / L2;
  int ans = 0;
  tt = "";
  for (int i = 1; i <= cc; i++) {
    tt += m2;
    if ((cc % i)) continue;
    ans += vis[tt];
  }
  cout << ans << endl;
  return 0;
}
