#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 10007;
int n;
long long ar[MAXN];
int ka;
void init();
void input();
void work();
void solve1(long long l, long long r);
void solve2_1(long long l, long long r);
void solve2_2(long long l, long long r);
void solve3_1(long long l, long long r);
void solve3_2(long long l, long long r);
void solve4_1(long long l, long long r);
void solve4_2(long long l, long long r);
void solve4_3(long long l, long long r);
void solve4_4(long long l, long long r);
void solve5(long long l, long long r);
int query() {
  printf("%d ", ka);
  for (int i = 1; i <= ka; ++i) printf("%I64d ", ar[i]);
  putchar('\n');
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  if (ans < 0) exit(0);
  return ans;
}
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {}
void work() { solve1(1, 10004205361450474LL); }
void solve1(long long l, long long r) {
  long long mid = 204761410474LL;
  ar[ka = 1] = mid;
  int ret = query();
  if (!ret)
    solve2_1(1, mid - 1);
  else
    solve2_2(mid + 1, r);
}
void solve2_1(long long l, long long r) {
  ar[ka = 1] = 2046;
  int ret = query();
  if (!ret)
    solve3_1(l, 2045);
  else
    solve3_2(2047, r);
}
void solve2_2(long long l, long long r) {
  for (int _t = 4; _t > 0; --_t) {
    long long l1 = 1;
    for (int i = 1; i < _t; ++i) l1 *= 10001;
    ka = 10000;
    for (int i = 1; i <= ka; ++i) ar[i] = l - 1 + l1 * i;
    ar[0] = l - 1, ar[ka + 1] = r + 1;
    int ret = query();
    l = ar[ret] + 1, r = ar[ret + 1] - 1;
  }
}
void solve3_1(long long l, long long r) {
  ar[ka = 1] = 6;
  int ret = query();
  if (!ret)
    solve4_1(l, 5);
  else
    solve4_2(7, r);
}
void solve3_2(long long l, long long r) {
  ar[0] = l - 1;
  ka = 2047;
  for (int i = 1; i <= ka; ++i) ar[i] = 20468427 + 10001LL * 10001 * (i - 1);
  ar[ka + 1] = r + 1;
  int ret = query();
  if (!ret)
    solve4_3(l, ar[1] - 1);
  else
    solve4_4(ar[ret] + 1, ar[ret + 1] - 1);
}
void solve4_1(long long l, long long r) {
  ar[ka = 1] = 2;
  int ret = query();
  if (!ret)
    solve5(l, 1);
  else
    solve5(3, r);
}
void solve4_2(long long l, long long r) {
  ka = 7;
  ar[0] = l - 1;
  for (int i = 1; i <= ka; ++i) ar[i] = ar[i - 1] * 2 + 2;
  ar[ka + 1] = r + 1;
  int ret = query();
  solve5(ar[ret] + 1, ar[ret + 1] - 1);
}
void solve4_3(long long l, long long r) {
  ar[0] = l - 1;
  ar[1] = 4094;
  ar[2] = 8190;
  ka = 2047;
  for (int i = 0; i < 2045; ++i) ar[i + 3] = 16382 + 10001 * i;
  ar[ka + 1] = r + 1;
  int ret = query();
  solve5(ar[ret] + 1, ar[ret + 1] - 1);
}
void solve4_4(long long l, long long r) {
  ar[0] = l - 1;
  ka = 10000;
  for (int i = 1; i <= ka; ++i) ar[i] = ar[i - 1] + 10001;
  ar[ka + 1] = r + 1;
  int ret = query();
  solve5(ar[ret] + 1, ar[ret + 1] - 1);
}
void solve5(long long l, long long r) {
  ka = r - l + 1;
  for (int i = 1; i <= ka; ++i) ar[i] = l + i - 1;
  query();
}
