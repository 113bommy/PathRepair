#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
char str[1000005];
int A[16][16];
int O[16][16];
int X[16][16];
int match[1000005];
int stk[1000005], top;
int parse(int l, int r) {
  if (l >= r) {
    if (str[l] == '0') return 1;
    if (str[l] == '1') return 8;
    if (str[l] == '?') return 6;
    fprintf(stderr, "str[%d] = %c\n", l, str[l]);
    assert(false);
  }
  int L = parse(l + 1, match[l + 1]);
  int R = parse(match[r - 1], r - 1);
  char op = str[match[l + 1] + 1];
  if (op == '&') return A[L][R];
  if (op == '|') return O[L][R];
  if (op == '^') return X[L][R];
  assert(false);
}
int main() {
  for (int i = 0; i < 16; ++i)
    for (int j = 0; j < 16; ++j)
      for (int x = 0; x < 4; ++x)
        for (int y = 0; y < 4; ++y) {
          if (!(i & (1 << x))) continue;
          if (!(j & (1 << x))) continue;
          int a = x >> 1, b = x & 1;
          int c = y >> 1, d = y & 1;
          int e, f;
          e = a & c, f = b & d;
          A[i][j] = 1 << ((e << 1) ^ f);
          e = a | c, f = b | d;
          O[i][j] = 1 << ((e << 1) ^ f);
          e = a ^ c, f = b ^ d;
          X[i][j] = 1 << ((e << 1) ^ f);
        }
  scanf("%*d\n%s", str);
  int n = (int)strlen(str);
  for (int i = 0; i < n; ++i) {
    match[i] = i;
    if (str[i] == '(')
      stk[++top] = i;
    else if (str[i] == ')') {
      int l = stk[top--];
      match[l] = i;
      match[i] = l;
    }
  }
  if (parse(0, n - 1) & 6)
    puts("YES");
  else
    puts("NO");
  return 0;
}
