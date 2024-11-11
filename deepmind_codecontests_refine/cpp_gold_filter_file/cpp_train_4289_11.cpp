#include <bits/stdc++.h>
using namespace std;
int table[20];
long long tot = 0;
int nns[20];
bool isluck(int k) {
  while (k) {
    if (k % 10 != 4 && k % 10 != 7) return false;
    k /= 10;
  }
  return true;
}
int luckns[2000];
int tol = 0;
void maketable(int i, int np) {
  if (i == 9) return;
  int np1 = np * 10 + 4, np2 = np * 10 + 7;
  luckns[tol++] = np1;
  luckns[tol++] = np2;
  maketable(i + 1, np1);
  maketable(i + 1, np2);
}
int main() {
  maketable(0, 0);
  table[1] = 1;
  for (tot = 2; table[tot - 1] * tot < 1000000000; ++tot)
    table[tot] = table[tot - 1] * tot;
  tot--;
  int n, k;
  scanf("%d%d", &n, &k);
  if (n <= tot && table[n] < k)
    puts("-1");
  else {
    int pi;
    for (pi = tot; table[pi] >= k; --pi)
      ;
    int summ = 0;
    for (int i = 0; i < tol; ++i)
      if (luckns[i] >= 1 && luckns[i] < n - pi) summ++;
    for (int i = n - pi; i <= n; ++i) nns[i - n + pi + 1] = i;
    int top = pi;
    int tns = n - pi;
    k--;
    while (top) {
      int p1 = k / table[top] + 1;
      for (int i = 1; i <= pi + 1; ++i)
        if (nns[i] != -1) {
          p1--;
          if (p1 == 0) {
            if (isluck(nns[i]) && isluck(tns)) summ++;
            nns[i] = -1;
            break;
          }
        }
      k %= table[top];
      tns++;
      top--;
    }
    for (int i = 1; i <= pi + 1; ++i)
      if (nns[i] != -1) {
        if (isluck(nns[i]) && isluck(n)) summ++;
        break;
      }
    printf("%d\n", summ);
  }
  return 0;
}
