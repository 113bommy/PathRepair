#include <bits/stdc++.h>
using namespace std;
int T[4001000];
int qnt[1001000];
void update(int idx, int val) {
  idx++;
  while (idx < 4001000) {
    T[idx] += val;
    idx += idx & -idx;
  }
}
void add(int x) {
  if (++qnt[x] == 1) update(x, 1);
}
void dec(int x) {
  if (--qnt[x] == 0) update(x, -1);
}
int search() {
  int ret = 0;
  for (int i = 21; i >= 0; i--)
    if (T[ret + (1 << i)] == (1 << i)) ret += (1 << i);
  return ret;
}
int nim[1001000];
long long v[100100];
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) scanf("%I64d", v + i);
  sort(v, v + n);
  long long pa = 1, pb = 0;
  long long t = 2;
  int p = 0;
  while (v[p] == 1) p++;
  while (t <= 1001000 && p < n) {
    while ((pb + 1) * (pb + 1) <= t) add(nim[pb + 1]), pb++;
    while (pa * pa * pa * pa < t) dec(nim[pa]), pa++;
    nim[t] = search();
    ;
    while (v[p] == t && p < n) ans ^= nim[t], p++;
    t++;
  }
  while (p < n) {
    t = v[p];
    while ((pb + 1) * (pb + 1) <= t) add(nim[pb + 1]), pb++;
    while (pa * pa * pa * pa < t) dec(nim[pb]), pa++;
    while (v[p] == t && p < n) ans ^= search(), p++;
  }
  printf("%s\n", ans ? "Furlo" : "Rublo");
}
