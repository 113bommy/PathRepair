#include <bits/stdc++.h>
using namespace std;
long long int L, R;
int l[20], r[20];
int cur[10], chg[10];
long long int ans;
int sz;
int exis(int in, int fin) {
  int i;
  for (i = in; i <= fin; i++)
    if (chg[i]) return 1;
  return 0;
}
int test(int pos, int lf, int rf) {
  if (pos == sz) return 1;
  if (lf && rf) {
    if (l[pos] == r[pos]) {
      if (chg[l[pos]]) {
        chg[l[pos]]--;
        if (test(pos + 1, 1, 1)) return 1;
        chg[l[pos]]++;
      }
      return 0;
    }
    if (exis(l[pos] + 1, r[pos] - 1)) return 1;
    if (chg[l[pos]]) {
      chg[l[pos]]--;
      if (test(pos + 1, 1, 0)) return 1;
      chg[l[pos]]++;
    }
    if (chg[r[pos]]) {
      chg[r[pos]]--;
      if (test(pos + 1, 0, 1)) return 1;
      chg[r[pos]]++;
    }
    return 0;
  } else if (rf) {
    if (exis(0, r[pos] - 1)) return 1;
    if (chg[r[pos]]) {
      chg[r[pos]]--;
      if (test(pos + 1, 0, 1)) return 1;
      chg[r[pos]]++;
    }
    return 0;
  } else if (lf) {
    if (exis(l[pos] + 1, 9)) return 1;
    if (chg[l[pos]]) {
      chg[l[pos]]--;
      if (test(pos + 1, 1, 0)) return 1;
      chg[l[pos]]++;
    }
    return 0;
  }
  return 0;
}
void brute(int ls, int tot) {
  if (ls == 10) {
    int i;
    for (i = 0; i < 10; i++) chg[i] = cur[i];
    chg[0] = tot;
    if (test(0, 1, 1)) ans++;
    return;
  }
  int i;
  for (i = 0; i <= tot; i++) {
    cur[ls] = i;
    brute(ls + 1, tot - i);
  }
}
int main() {
  memset(cur, 0, sizeof cur);
  memset(chg, 0, sizeof chg);
  scanf("%lld%lld", &L, &R);
  int sl = 0, sr = 0;
  if (L == R) {
    printf("1\n");
    return 0;
  }
  while (L) {
    l[sl++] = L % 10;
    L /= 10;
  }
  while (R) {
    r[sr++] = R % 10;
    R /= 10;
  }
  while (sl < sr) l[sl++] = 0;
  sz = sr;
  reverse(l, l + sl);
  reverse(r, r + sr);
  brute(1, sr);
  printf("%lld\n", ans);
  return 0;
}
