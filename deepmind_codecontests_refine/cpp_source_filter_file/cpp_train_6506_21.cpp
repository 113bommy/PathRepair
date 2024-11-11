#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100005];
long long ans = 0;
int main() {
  scanf("%d%d%s", &n, &m, s);
  int k = 1;
  for (int i = 0; i < (int)(n - 1); ++i)
    if (s[i] != s[i + 1]) {
      ++k;
    }
  ans = (long long)n * (m - 1) * k;
  for (int beg = 0; beg < n - 1;)
    if (s[beg] != s[beg + 1]) {
      int end = beg + 2;
      while (end < n && s[end] == s[beg]) ++end;
      int sz = end - beg;
      ans -= (long long)sz * (sz - 1) / 2;
      beg = end - 1;
    } else {
      ++beg;
    }
  cout << ans << endl;
  return 0;
}
