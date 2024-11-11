#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 1.4e7;
int n, a[N], ans[N], l[M];
vector<int> v[2];
void no() {
  puts("NO");
  exit(0);
}
void yes() {
  puts("YES");
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  exit(0);
}
signed main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), v[a[i] & 1].push_back(a[i]);
  sort(a, a + n);
  if (unique(a, a + n) - a != n) {
    for (int i = 0; i < n - 1; i++) ans[i] = a[i];
    yes();
  }
  if (!v[0].empty()) {
    vector<int> fi;
    if (v[0].size() >= 3)
      fi = {v[0][0], v[0][1], v[0][2]};
    else if (v[1].size() >= 2)
      fi = {v[0][0], v[1][0], v[1][1]};
    else
      no();
    for (int i = 0; i < 3; i++)
      ans[i] = (fi[i] + fi[(i + 1) % 3] - fi[(i + 2) % 3]) / 2;
    int sz = 3;
    for (int i = 0; i < n; i++) {
      int fl = 1;
      for (int j = 0; j < 3; j++)
        if (a[i] == fi[j]) {
          fl = 0;
          break;
        }
      if (fl) ans[sz++] = a[i] - ans[0];
    }
    yes();
  }
  int m = min(26, n), s1 = -1, s2 = -1;
  for (int i = 0; i < (1 << m); i++)
    if (__builtin_popcount(i) == m / 2) {
      int s = 0;
      for (int j = 0; j < m; j++)
        if (i >> j & 1) s += v[1][j];
      if (l[s]) {
        s1 = l[s];
        s2 = i;
        break;
      }
      l[s] = i;
    }
  if (s1 == -1) no();
  int ss = s1 & s2;
  s1 ^= ss;
  s2 ^= ss;
  vector<int> v1, v2, f;
  for (int i = 0; i < m; i++) {
    if (s1 >> i & 1) v1.push_back(v[1][i]);
    if (s2 >> i & 1) v2.push_back(v[1][i]);
  }
  for (int i = 0; i < v1.size(); i++) f.push_back(v1[i]), f.push_back(v2[i]);
  for (int i = 1; i < f.size(); i++) ans[i] = f[i - 1] - ans[i - 1];
  int sz = f.size();
  for (int i = 0; i < n; i++)
    if (i >= m || !((s1 | s2) >> i & 1)) ans[sz++] = v[1][i] - ans[0];
  yes();
  return 0;
}
