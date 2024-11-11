#include <bits/stdc++.h>
using namespace std;
vector<int> suc;
int fail[200000 + 5];
void calfail(char *p) {
  int j = 0, l = strlen(p);
  fail[0] = 0;
  for (int i = 1; i <= l - 1; i++) {
    while (j && p[j] != p[i]) j = fail[j - 1];
    if (p[j] == p[i]) j++;
    fail[i] = j;
  }
  return;
}
void kmp(char *p, char *t) {
  suc.clear();
  int n = strlen(t), m = strlen(p), j = 0;
  for (int i = 0; i <= n - 1; i++) {
    while (j && p[j] != t[i]) j = fail[j - 1];
    if (p[j] == t[i]) j++;
    if (j == m) suc.push_back(i - m + 1);
  }
  return;
}
int n, m;
char s[200000 + 5], t[200000 + 5];
char S[200000 + 5], T[200000 + 5];
int ans[200000 + 5];
void check(int a, int b) {
  for (int i = 0; i <= n - 1; i++)
    s[i] = S[i] == 'a' + a ? '1' : S[i] == 'a' + b ? '2' : '0';
  for (int i = 0; i <= m - 1; i++)
    t[i] = T[i] == 'a' + b ? '1' : T[i] == 'a' + a ? '2' : '0';
  calfail(t);
  kmp(t, s);
  for (auto p : suc) ans[p] |= 1 << a, ans[p] |= 1 << b;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s%s", S, T);
  for (int i = 0; i <= 25; i++)
    for (int j = i; j <= 25; j++) check(i, j);
  vector<int> A;
  int V = (1 << 26) - 1;
  for (int i = 0; i <= n - 1; i++)
    if (ans[i] == V) A.push_back(i);
  int l = A.size();
  printf("%d\n", l);
  for (int i = 0; i <= l - 1; i++) printf("%d%c", A[i] + 1, " \n"[i == l - 1]);
  return 0;
}
