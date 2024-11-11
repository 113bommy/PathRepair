#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, m, cst[N + 1];
char s[N + 1], nd, nd2;
void pl(int of) {
  int i = 0, c = 0, lst = -1;
  while (i + 1 + of < m) {
    if (i + of - 1 >= 0) {
      if (s[i + of - 1] == '?')
        ++c;
      else if (s[i + of - 1] != nd2)
        lst = i + of - 1;
    }
    if (s[i + of] == '?')
      ++c;
    else if (s[i + of] != nd)
      lst = i + of;
    cst[i + of + 1] = -1;
    i += 2;
  }
  while (i + of < n) {
    if (s[i + of - 1] == '?')
      ++c;
    else if (s[i + of - 1] != nd2)
      lst = i + of - 1;
    if (s[i + of] == '?')
      ++c;
    else if (s[i + of] != nd)
      lst = i + of;
    int z = i - m;
    if (z + of - 1 >= 0 && s[z + of - 1] == '?') --c;
    if (z + of >= 0 && s[z + of] == '?') --c;
    cst[i + of + 1] = lst <= z + of ? c : -1;
    i += 2;
  }
}
struct D {
  int oc, cst;
  D() : oc(0), cst(0) {}
  D(int a, int b) : oc(a), cst(b) {}
  D operator+(int x) { return D(oc + 1, cst + x); }
  D operator^(D o) {
    if (oc == o.oc) {
      if (cst < o.cst) return *this;
      return o;
    }
    if (oc < o.oc) return o;
    return *this;
  }
  void pr() { printf("%d %d\n", oc, cst); }
} dp[N + 1];
int main() {
  scanf("%d%s%d", &n, s, &m);
  if (m & 1)
    nd = 'a', nd2 = 'b';
  else
    nd = 'b', nd2 = 'a';
  if (m == 1) {
    for (int i = 1; i < (int)(n + 1); ++i)
      if (s[i - 1] == '?')
        cst[i] = 1;
      else if (s[i - 1] == 'b')
        cst[i] = -1;
  } else
    pl(0), pl(1);
  for (int i = m; i < (int)(n + 1); ++i) {
    dp[i] = dp[i - 1];
    if (cst[i] != -1) dp[i] = dp[i] ^ dp[i - m] + cst[i];
  }
  printf("%d\n", dp[n].cst);
}
