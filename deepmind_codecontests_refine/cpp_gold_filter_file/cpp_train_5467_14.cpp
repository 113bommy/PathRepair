#include <bits/stdc++.h>
using namespace std;
int n, m, h, w, len;
char s[1000000];
unordered_map<int, long long> mpx, mpy;
int mp[300];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
long long a[1000000], b[1000000], pb[1000000];
void find(long long *a, int n, int x, int maxx, int minx,
          unordered_map<int, long long> mp) {
  for (int i = (0); i <= (n); i++) a[i] = 1LL << 60;
  for (int i = (0); i <= (n); i++)
    if (mp.count(-i - 1)) a[i] = min(a[i], mp[-i - 1]);
  for (int i = (0); i <= (n); i++)
    if (mp.count(n - i)) a[i] = min(a[i], mp[n - i]);
  for (int i = (0); i <= (n); i++) {
    long long tmp = 1LL << 60, turn;
    if (x > 0) {
      turn = max(0.0, ceil((n - i - maxx) * 1.0 / x));
      tmp = turn * len + mp[n - turn * x - i];
    } else if (x < 0) {
      int tx = -x;
      turn = max(0.0, ceil((i + 1 + minx) * 1.0 / tx));
      tmp = turn * len + mp[-(1 + i + turn * x)];
    }
    a[i] = min(a[i], tmp);
  }
}
int main() {
  mp['U'] = 0;
  mp['D'] = 1;
  mp['L'] = 2;
  mp['R'] = 3;
  scanf("%d%d%d%s", &n, &h, &w, s);
  len = n;
  int x = 0, y = 0;
  int maxx = 0, maxy = 0, minx = 0, miny = 0;
  mpx[0] = 0;
  mpy[0] = 0;
  for (int i = (0); i < (n); i++) {
    int dir = mp[s[i]];
    x += dx[dir];
    y += dy[dir];
    maxx = max(maxx, x);
    maxy = max(maxy, y);
    minx = min(minx, x);
    miny = min(miny, y);
    if (!mpx.count(x)) mpx[x] = i + 1;
    if (!mpy.count(y)) mpy[y] = i + 1;
  }
  if (!x && !y && (maxx - minx) < h && (maxy - miny) < w) {
    puts("-1");
    return 0;
  }
  find(a, h, x, maxx, minx, mpx);
  find(b, w, y, maxy, miny, mpy);
  sort(b, b + w);
  for (int i = (0); i < (w); i++) pb[i + 1] = (pb[i] + b[i]) % 1000000007;
  long long ans = 0;
  for (int i = (0); i < (h); i++) {
    long long p = lower_bound(b, b + w, a[i]) - b;
    ans = (ans + (w - p) * a[i] + pb[p]) % 1000000007;
  }
  printf("%lld\n", ans % 1000000007);
  return 0;
}
