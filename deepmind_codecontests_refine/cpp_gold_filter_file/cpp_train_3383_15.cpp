#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000000 + 50;
int pcnt, p, q;
int flag[MAXN], prime[MAXN], ppcnt[MAXN], pacnt[MAXN];
void get_prime(int n) {
  for (int i = 2; i <= n; i++) {
    if (!flag[i]) {
      prime[pcnt++] = i;
      ppcnt[i] = pcnt;
    }
    for (int j = 0; j < pcnt && i * prime[j] <= n; j++) {
      flag[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
}
bool ispalin(int x) {
  char s[20];
  sprintf(s, "%d", x);
  for (int i = 0, t = strlen(s) / 2, len = strlen(s); i < t; i++)
    if (s[i] != s[len - i - 1]) return false;
  return true;
}
int main() {
  get_prime(MAXN - 50);
  for (int i = 2; i <= MAXN - 50; i++)
    if (ppcnt[i] == 0) ppcnt[i] = ppcnt[i - 1];
  for (int i = 1; i <= MAXN; i++) pacnt[i] = pacnt[i - 1] + ispalin(i);
  scanf("%d%d", &p, &q);
  if (p == q) {
    for (int i = 50; i > 10; i--)
      if (pacnt[i] == ppcnt[i]) {
        printf("%d\n", i);
        return 0;
      }
  } else if (q > p) {
    for (int i = 50; i >= 1; i--)
      if (ppcnt[i] * q <= pacnt[i] * p) {
        printf("%d\n", i);
        return 0;
      }
  } else {
    for (int i = MAXN - 50; i > 35; i--)
      if (ppcnt[i] * q <= pacnt[i] * p) {
        printf("%d\n", i);
        return 0;
      }
  }
  printf("Palindromic tree is better than splay tree\n");
  return 0;
}
