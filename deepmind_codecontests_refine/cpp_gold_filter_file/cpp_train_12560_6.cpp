#include <bits/stdc++.h>
using namespace std;
char S[500005], T[500005];
int a, b, c, d, n, m, Q;
int Sa[500005], Sb[500005], Ta[500005], Tb[500005];
int taS[500005], taT[500005];
int ans, leS, leT, TS, TT;
void read(int &x) {
  x = 0;
  int k = 1;
  char c = getchar();
  while ((c != '-') && (c < '0' || c > '9')) c = getchar();
  if (c == '-') k = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  x = x * k;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void init() { freopen("e.in", "r", stdin); }
int main() {
  scanf("%s\n", S);
  n = strlen(S);
  for (int i = 1; i <= n; i++) {
    Sa[i] = Sa[i - 1] + (S[i - 1] == 'A');
    Sb[i] = Sb[i - 1] + (S[i - 1] != 'A');
    if (S[i - 1] == 'A') taS[i] = taS[i - 1] + 1;
  }
  scanf("%s\n", T);
  m = strlen(T);
  for (int i = 1; i <= m; i++) {
    Ta[i] = Ta[i - 1] + (T[i - 1] == 'A');
    Tb[i] = Tb[i - 1] + (T[i - 1] != 'A');
    if (T[i - 1] == 'A') taT[i] = taT[i - 1] + 1;
  }
  read(Q);
  while (Q--) {
    read(a), read(b), read(c), read(d);
    ans = 1;
    leS = Sb[b] - Sb[a - 1], leT = Tb[d] - Tb[c - 1];
    int dif = leT - leS;
    TS = min(taS[b], b - a + 1), TT = min(taT[d], d - c + 1);
    if (dif < 0 || TS < TT || dif % 2) ans = 0;
    if (dif < ((TS - TT) % 3 > 0) * 2) ans = 0;
    if (Sb[b] == Sb[a - 1] && TS == TT && dif) ans = 0;
    write(ans);
  }
  return 0;
}
