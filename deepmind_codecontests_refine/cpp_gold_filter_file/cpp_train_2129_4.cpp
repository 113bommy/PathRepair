#include <bits/stdc++.h>
using namespace std;
set<string> se;
const int maxn = 111111;
const int maxm = 111111;
int n;
char s[111][4];
int ma[5][5];
int nu(char s) {
  if (s == 'B') {
    return 0;
  } else if (s == 'Y') {
    return 1;
  } else if (s == 'W') {
    return 2;
  } else if (s == 'G') {
    return 3;
  } else {
    return 4;
  }
}
int num;
int tn;
int ans = 0;
int a[5];
int b[5];
void dfs(int q, int w, int deep) {
  if (deep == ans) return;
  set<string>::iterator it, itt;
  string s, ss;
  int f = 0;
  for (it = se.begin(); it != se.end(); it++) {
    for (itt = se.begin(); itt != it; itt++) {
      s = *it;
      ss = *itt;
      if (s[0] != ss[0] && (a[nu(s[0])] || a[nu(ss[0])])) continue;
      if (s[1] != ss[1] && (b[s[1] - '1'] || b[ss[1] - '1'])) continue;
      f = 1;
      break;
    }
    if (f) break;
  }
  if (f == 0) {
    ans = deep;
    return;
  }
  for (int i = q + 1; i < 5; i++) {
    if (!a[i]) {
      a[i] = 1;
      dfs(i, w, deep + 1);
      a[i] = 0;
    }
  }
  for (int i = w + 1; i < 5; i++) {
    if (!b[i]) {
      b[i] = 1;
      dfs(q, i, deep + 1);
      b[i] = 0;
    }
  }
}
void slove() {
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  ans = 111;
  se.clear();
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    se.insert(s[i]);
  }
  dfs(-1, -1, 0);
  cout << ans << endl;
}
int main() {
  int t;
  while (~scanf("%d", &n)) {
    slove();
  }
  return 0;
}
