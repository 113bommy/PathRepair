#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char s[N], t[N];
int p[N], tm[N];
int n, m;
bool ck(int x) {
  int r = 1;
  for (int i = 1; i <= n; ++i)
    if (tm[i] > x) {
      if (s[i] == t[r]) ++r;
      if (r > m) return 1;
    }
  return 0;
}
int main() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  for (int i = 1; i <= n; ++i) scanf("%d", p + i);
  for (int i = 1; i <= n; ++i) tm[p[i]] = i;
  int l = 0, r = n;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    if (ck(m))
      l = m;
    else
      r = m - 1;
  }
  cout << l << endl;
  return 0;
}
