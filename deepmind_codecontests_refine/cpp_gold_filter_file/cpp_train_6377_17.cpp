#include <bits/stdc++.h>
using namespace std;
bool chin(char c, string T) {
  int i;
  for (i = 0; i <= ((int)(T).size()) - 1; ++i)
    if (T[i] == c) return true;
  return false;
}
int n, i, a[500040], tr[6000000], balance, q, cnt, maxlen;
char s[500040];
void prepare() {
  int i;
  for (i = 0; i <= 4 * (900080 + 7); ++i) tr[i] = (int)1e9;
}
void modify(int l, int v) {
  for (int i = l; i <= 900080; i = (i | (i - 1)) + 1) tr[i] = min(tr[i], v);
}
int calcmin(int r) {
  int s = (int)1e9;
  for (int i = r; i; i &= (i - 1)) s = min(s, tr[i]);
  return s;
}
void newbalance(int balance, int pos) { modify(balance + 500020, pos); }
int exmin(int balance) {
  int maxsub = balance;
  return calcmin(maxsub + 500020);
}
int main(int argc, const char *argv[]) {
  prepare();
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (i = 1; i <= n; ++i) a[i] = (chin(s[i], "aeiouAEIOU") ? -1 : 2);
  balance = 0;
  newbalance(0, 0);
  for (i = 1; i <= n; ++i) {
    balance += a[i];
    q = exmin(balance);
    if (i - q > maxlen)
      maxlen = i - q, cnt = 1;
    else {
      if (i - q == maxlen) ++cnt;
    }
    newbalance(balance, i);
  }
  if (cnt == 0)
    puts("No solution");
  else
    printf("%d %d\n", maxlen, cnt);
  return 0;
}
