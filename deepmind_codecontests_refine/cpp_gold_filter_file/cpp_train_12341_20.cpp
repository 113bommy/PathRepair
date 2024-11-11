#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, MOD = 1e9 + 7;
const long long INF = 9e18;
namespace IStream {
const int LLL = 1 << 15;
char buffer[LLL + 5], *s, *t;
inline char get_char() {
  if (s == t) {
    t = (s = buffer) + fread(buffer, 1, LLL, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int get_int() {
  char c, flg = 1;
  int ret = 0;
  while (c = get_char(), c < '0' || c > '9')
    if (c == '-') flg = -1;
  while (c >= '0' && c <= '9')
    ret = (ret << 1) + (ret << 3) + (c - '0'), c = get_char();
  return ret * flg;
}
inline long long get_LL() {
  char c, flg = 1;
  long long ret = 0;
  while (c = get_char(), c < '0' || c > '9')
    if (c == '-') flg = -1;
  while (c >= '0' && c <= '9')
    ret = (ret << 1) + (ret << 3) + (c - '0'), c = get_char();
  return ret * flg;
}
}  // namespace IStream
using namespace IStream;
struct Point {
  long long x, y, z;
} p[N];
int n;
Point now;
int check(long long mid) {
  long long l[5] = {0, -INF, -INF, -INF, -INF}, r[5] = {0, INF, INF, INF, INF};
  for (int i = 1; i <= n; i++) {
    l[1] = max(l[1], p[i].x + p[i].y + p[i].z - mid);
    r[1] = min(r[1], p[i].x + p[i].y + p[i].z + mid);
    l[2] = max(l[2], p[i].x + p[i].y - p[i].z - mid);
    r[2] = min(r[2], p[i].x + p[i].y - p[i].z + mid);
    l[3] = max(l[3], p[i].x - p[i].y + p[i].z - mid);
    r[3] = min(r[3], p[i].x - p[i].y + p[i].z + mid);
    l[4] = max(l[4], -p[i].x + p[i].y + p[i].z - mid);
    r[4] = min(r[4], -p[i].x + p[i].y + p[i].z + mid);
  }
  for (int i = 0; i < 2; i++) {
    long long ll[5], rr[5];
    int suc = 1;
    for (int i = 0; i < 5; i++) ll[i] = l[i], rr[i] = r[i];
    for (int j = 1; j <= 4; j++) {
      if ((ll[j] & 1) == (i ^ 1)) ll[j]++;
      if ((rr[j] & 1) == (i ^ 1)) rr[j]--;
      if (ll[j] > rr[j]) suc = 0;
    }
    if (!suc || rr[2] + rr[3] + rr[4] < ll[1] || ll[2] + ll[3] + ll[4] > rr[1])
      continue;
    long long a, b, c, inc;
    a = ll[2], b = ll[3], c = ll[4];
    inc = max(0ll, ll[1] - a - b - c);
    long long t;
    t = min(rr[2] - ll[2], inc);
    a += t;
    inc -= t;
    t = min(rr[3] - ll[3], inc);
    b += t;
    inc -= t;
    t = min(rr[4] - ll[4], inc);
    c += t;
    inc -= t;
    if (inc) continue;
    long long ax, ay, az;
    ax = a + b >> 1, ay = a + c >> 1, az = b + c >> 1;
    now = {ax, ay, az};
    return 1;
  }
  return 0;
}
int Solve(int cas = 0) {
  n = get_int();
  for (int i = 1; i <= n; i++) {
    p[i].x = get_LL();
    p[i].y = get_LL();
    p[i].z = get_LL();
  }
  long long l = 0, r = 3e18, mid;
  Point ans;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1, ans = now;
    else
      l = mid + 1;
  }
  printf("%lld %lld %lld\n", ans.x, ans.y, ans.z);
  return 0;
}
void Pre() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  Pre();
  int cas;
  cas = get_int();
  for (int i = 1; i <= cas; i++) {
    Solve(i);
  }
  return 0;
}
