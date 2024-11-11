#include <bits/stdc++.h>
using namespace std;
char p[200000 + 5];
char t[200000 + 5];
int num[200000 + 5];
int plen, tlen;
bool check(int x) {
  int ans = 0;
  for (int i = 0; i < plen; i++) {
    if (num[i] < x) continue;
    if (ans == tlen) return true;
    if (p[i] == t[ans]) ans++;
  }
  if (ans == tlen) return true;
  return false;
}
int fun(int l, int r) {
  if (l == r) return l;
  if (l == r - 1) {
    if (check(r))
      return r;
    else
      return l;
  }
  int mid = (l + r) >> 1;
  if (check(mid))
    return fun(mid, r);
  else
    return fun(l, mid - 1);
}
int main() {
  while (cin >> p >> t) {
    plen = strlen(p);
    tlen = strlen(t);
    int x;
    for (int i = 0; i < plen; i++) {
      scanf("%d", &x);
      num[x - 1] = i;
    }
    int ans = plen - tlen;
    printf("%d\n", fun(1, ans));
  }
  return 0;
}
