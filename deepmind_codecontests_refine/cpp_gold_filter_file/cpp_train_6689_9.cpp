#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
pair<int, int> c[maxn];
int chk(long long s, long long e) {
  if (e == s) return 0;
  if (e == s + 1) return 1;
  if (e & 1) {
    if (s & 1) return 0;
    return 1;
  }
  if (s <= e / 4) return chk(s, e / 4);
  if (s > (e / 4) * 2)
    return ((e - s) & 1);
  else
    return 1;
}
int lck(long long s, long long e) {
  if (2 * s > e) return 1;
  long long w = e / 2 + 3;
  while (w * 2 > e) w--;
  return chk(s, w);
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    c[i] = {chk(x, y), lck(x, y)};
  }
  int f = 1, s = 0;
  for (int i = 0; i < n; i++) {
    if (f == 1 && s == 1) break;
    if (f == 0 && s == 0) break;
    if (s == 1) {
      c[i].first ^= 1;
      c[i].second ^= 1;
    }
    f = c[i].second;
    s = c[i].first;
  }
  printf("%d %d\n", s, f);
  return 0;
}
