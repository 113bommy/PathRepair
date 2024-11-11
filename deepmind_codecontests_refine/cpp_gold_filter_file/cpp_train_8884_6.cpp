#include <bits/stdc++.h>
#pragma comment(linker, "/stack:16000000")
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 1000010;
char s[maxn];
int corr[maxn] = {};
int go(int fr, int to) {
  if (fr == to) {
    if (s[fr] == '0')
      return 1;
    else if (s[fr] == '1')
      return 1 << 15;
    else
      return (1 << 12) | (1 << 10);
  }
  int opi = -1;
  if (s[fr] == '(') {
    if (corr[fr] == to) return go(fr + 1, to - 1);
    opi = corr[fr] + 1;
  } else
    opi = fr + 1;
  int lval = go(fr, opi - 1);
  int rval = go(opi + 1, to);
  int res = 0;
  if (s[opi] == '^')
    for (int i = 0; i < 16; ++i)
      if (lval & (1 << i))
        for (int j = 0; j < 16; ++j)
          if (rval & (1 << j)) {
            res |= 1 << (i ^ j);
          }
  if (s[opi] == '|')
    for (int i = 0; i < 16; ++i)
      if (lval & (1 << i))
        for (int j = 0; j < 16; ++j)
          if (rval & (1 << j)) {
            res |= 1 << (i | j);
          }
  if (s[opi] == '&')
    for (int i = 0; i < 16; ++i)
      if (lval & (1 << i))
        for (int j = 0; j < 16; ++j)
          if (rval & (1 << j)) {
            res |= 1 << (i & j);
          }
  return res;
}
int main() {
  int m;
  scanf("%d", &m);
  scanf("%s", s);
  int n = strlen(s);
  stack<int> st;
  for (int i = n - 1; i >= 0; --i)
    if (s[i] == ')')
      st.push(i);
    else if (s[i] == '(') {
      corr[i] = st.top();
      st.pop();
    }
  int res = go(0, n - 1);
  int good[12] = {1, 2, 4, 8, 14, 13, 11, 7, 12, 10, 3, 5};
  int mask = 0;
  for (int i = 0; i < 12; ++i) mask |= 1 << good[i];
  if (res & mask)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
