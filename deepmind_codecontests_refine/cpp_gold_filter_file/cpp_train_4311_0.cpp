#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
int j, n, l, i, h, q1, q2, x, y, m, k, t, ans, p1, p2, ans1, ans2, a[1000500],
    q, d[1000500], p;
string s, z;
set<char> ss;
void init() {
  cin >> s;
  n = s.size();
  cin >> k;
}
void solve() {
  for (j = 1; j <= n; j++) {
    ss.insert(s[j - 1]);
    a[s[j - 1]]++;
    d[s[j - 1]] = 1;
  }
  if (k < int(ss.size())) {
    printf("-1\n");
    return;
  }
  for (set<char>::iterator w = ss.begin(); w != ss.end(); w++) {
    z += *w;
  }
  while (int(z.size()) < k) {
    q = 0;
    for (j = 'a'; j <= 'z'; j++) {
      if (!d[j]) {
        continue;
      }
      p = a[j] / d[j];
      if (a[j] % d[j]) {
        p++;
      }
      if (p > q) {
        q = p;
        t = j;
      }
    }
    z += char(t);
    d[t]++;
  }
  q = 0;
  for (j = 'a'; j <= 'z'; j++) {
    if (!d[j]) {
      continue;
    }
    p = a[j] / d[j];
    if (a[j] % d[j]) {
      p++;
    }
    if (p > q) {
      q = p;
      t = j;
    }
  }
  printf("%d\n%s", q, z.c_str());
}
void answer() {}
int main() {
  init();
  solve();
  answer();
  return 0;
}
