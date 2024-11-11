#include <bits/stdc++.h>
using namespace std;
const int N = 5005000;
int n, m, K, fk[N], le[N], nx[N], ex[N];
char S[N], T[N];
struct ele {
  char s[N];
  int n;
  void addl(char* t, int L) {
    for (int i = 0; i < L; i++) s[++n] = t[i];
  }
  void addr(char* t, int L) {
    for (int i = 1; i <= L; i++) s[++n] = t[L - i];
  }
  void addw(char* t, int L) {
    int l = 0, r = L - 1;
    while (l < r && t[l] == t[r]) l++, r--;
    t[l] < t[r] ? addl(t, L) : addr(t, L);
  }
  bool operator<(const ele& a) const {
    for (int i = 1; i <= n; i++)
      if (s[i] ^ a.s[i]) return s[i] < a.s[i];
  }
  void print() { puts(s + 1); }
} ans0, ans1, ans2;
void ini() {
  for (int i = 1, j, k; i <= n;) {
    for (k = (j = i) + 1; k <= n && T[j] <= T[k]; k++)
      j = T[j] ^ T[k] ? i : j + 1;
    for (fk[++m] = i, le[m] = k - j; i <= j; i += k - j)
      ;
  }
  fk[m + 1] = n + 1;
  nx[1] = n;
  int x = 0, y = 0;
  for (int i = 2; i <= n; i++) {
    if (i <= y) nx[i] = min(nx[i - x + 1], y - i + 1);
    while (i + nx[i] <= n && T[1 + nx[i]] == T[i + nx[i]]) nx[i]++;
    if (i + nx[i] >= y) x = i, y = i + nx[i] - 1;
  }
  x = y = 0;
  for (int i = 1; i <= n; i++) {
    if (i <= y) ex[i] = min(nx[i - x + 1], y - i + 1);
    while (i + ex[i] <= n && T[1 + ex[i]] == S[i + ex[i]]) ex[i]++;
    if (i + ex[i] >= y) x = i, y = i + ex[i] - 1;
  }
}
bool cmp(int x, int y) {
  if (ex[n - y] < y - x) return y = n - y + 2, S[y + ex[y]] > T[1 + ex[y]];
  return y = y - x + 1, T[1 + nx[y]] > T[y + nx[y]];
}
void work2() {
  ans1 = ans0;
  ans2 = ans0;
  ans0.addl(T + fk[m - 0], fk[m + 1] - fk[m - 0]);
  ans0.addw(T + 1, fk[m - 0] - 1);
  ans1.addl(T + fk[m - 1], fk[m + 1] - fk[m - 1]);
  ans1.addw(T + 1, fk[m - 1] - 1);
  int o = 1;
  for (int i = 2; i <= fk[m + 1] - 1; i++)
    if (cmp(o, i)) o = i;
  ans2.addr(T + o, fk[m + 1] - o);
  ans2.addl(T + 1, o - 1);
  if (ans1 < ans0) ans0 = ans1;
  if (ans2 < ans0) ans0 = ans2;
}
int main() {
  scanf("%s%d", S + 1, &K);
  n = strlen(S + 1);
  for (int i = 1; i <= n; i++) T[i] = S[n - i + 1];
  ini();
  for (; K > 2 && m; K--) {
    if (le[m] == 1)
      for (; m && le[m] == 1; m--) ans0.addl(T + fk[m], fk[m + 1] - fk[m]);
    else
      ans0.addl(T + fk[m], fk[m + 1] - fk[m]), m--;
  }
  if (K == 1 || m <= 1)
    ans0.addw(T + 1, fk[m + 1] - 1);
  else
    work2();
  ans0.print();
}
