#include <bits/stdc++.h>
using namespace std;
const int N = 500500;
char s[N], t[N];
int n, m;
int fail[N];
int init() {
  fail[0] = fail[1] = 0;
  for (int i = 2; i <= n; i++) {
    int j = fail[i - 1];
    while (j > 0 && t[j] != t[i - 1]) {
      j = fail[j];
    }
    if (t[j] == t[i - 1]) j++;
    fail[i] = j;
  }
  return fail[n];
}
int main() {
  scanf("%s\n%s", s, t);
  n = strlen(s);
  int rs[2] = {0};
  for (int i = 0; i < n; i++) rs[s[i] ^ '0']++;
  m = strlen(t);
  int k = init();
  int tn[2] = {0}, atn[2] = {0};
  for (int i = 0; i < m; i++) {
    tn[t[i] ^ '0']++;
    if (i >= k) atn[t[i] ^ '0']++;
  }
  int ans = 0;
  if (rs[0] < tn[0] || rs[1] < tn[1]) {
  } else {
    rs[0] -= tn[0];
    rs[1] -= tn[1];
    printf("%s", t);
    ans = 1;
    while (rs[0] >= atn[0] && rs[1] >= atn[1]) {
      rs[0] -= atn[0], rs[1] -= atn[1];
      printf("%s", t + k);
      ans++;
    }
  }
  while (rs[0]--) printf("0");
  while (rs[1]--) printf("1");
  printf("\n");
  return 0;
}
