#include <bits/stdc++.h>
using namespace std;
typedef unsigned int UI;
typedef long int LI;
typedef unsigned long int ULI;
typedef long long int LL;
typedef unsigned long long int ULL;
const LL MOD = 1e9 + 7;
inline int scanInt() {
  int n = 0;
  char ch = getchar();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = (n << 1) + (n << 3) + (int)(ch - '0');
    ch = getchar();
  }
  return n * sign;
}
inline LL scanLong() {
  LL n = 0;
  char ch = getchar();
  LL sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = (n << 1) + (n << 3) + (LL)(ch - '0');
    ch = getchar();
  }
  return n * sign;
}
int main() {
  LL n = scanLong();
  ;
  LL m = scanLong();
  ;
  LL q = scanLong();
  ;
  LL perm[n], seq[m], next[m], last[m][22];
  map<LL, LL> next_perm, next_seq;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    perm[i] = scanLong();
    if (i > 0) next_perm[perm[i - 1]] = perm[i];
    if (i + 1 == n) next_perm[perm[i]] = perm[0];
  }
  for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
       i += 1 - 2 * ((0) > (m)))
    seq[i] = scanLong();
  for (__typeof(0) i = (m) - ((m) > (0)); i != (0) - ((m) > (0));
       i += 1 - 2 * ((m) > (0))) {
    LL req = next_perm[seq[i]];
    next_seq[seq[i]] = i;
    if (next_seq.find(req) == next_seq.end())
      next[i] = LONG_MAX;
    else
      next[i] = next_seq[req];
  }
  for (__typeof(20) i = (0) - ((0) > (20)); i != (20) - ((0) > (20));
       i += 1 - 2 * ((0) > (20))) {
    for (__typeof(0) j = (m) - ((m) > (0)); j != (0) - ((m) > (0));
         j += 1 - 2 * ((m) > (0))) {
      if (i == 0)
        last[j][i] = j;
      else if (i == 1)
        last[j][i] = next[j];
      else {
        LL n = last[j][i - 1];
        if (n == LONG_MAX || next[n] == LONG_MAX)
          last[j][i] = LONG_MAX;
        else
          last[j][i] = last[next[n]][i - 1];
      }
    }
  }
  LL lastn[m];
  LL pw = 0;
  while (n >= (1ll << pw)) pw++;
  for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
       i += 1 - 2 * ((0) > (m))) {
    LL t = n, a = i;
    for (__typeof(0) j = (pw) - ((pw) > (0)); j != (0) - ((pw) > (0));
         j += 1 - 2 * ((pw) > (0))) {
      if (a == LONG_MAX) break;
      if ((1ll << j) <= t) {
        a = last[a][j];
        t -= (1ll << j);
        if (t > 0 && a != LONG_MAX) a = next[a];
      }
    }
    lastn[i] = a;
  }
  LL table[m + 1][22];
  memset(table, 0, sizeof(table));
  for (__typeof(20) i = (0) - ((0) > (20)); i != (20) - ((0) > (20));
       i += 1 - 2 * ((0) > (20))) {
    for (__typeof(m) s = (0) - ((0) > (m)); s != (m) - ((0) > (m));
         s += 1 - 2 * ((0) > (m))) {
      LL e = s + (i > 0 ? (1ll << (i - 1)) : 0);
      if (i == 0)
        table[s][i] = lastn[s];
      else if (e < m)
        table[s][i] = min(table[s][i - 1], table[e][i - 1]);
      else
        table[s][i] = table[s][i - 1];
    }
  }
  for (__typeof(q) _ = (0) - ((0) > (q)); _ != (q) - ((0) > (q));
       _ += 1 - 2 * ((0) > (q))) {
    LL l = scanLong();
    ;
    LL r = scanLong();
    ;
    l--;
    r--;
    LL pw = 0;
    while ((r - l + 1) >= (1ll << pw)) pw++;
    pw--;
    LL m = min(table[l][pw], table[r - (1ll << pw) + 1][pw]);
    if (l <= m && m <= r)
      cout << 1;
    else
      cout << 0;
  }
  cout << endl;
}
