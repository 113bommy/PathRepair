#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 2e5 + 10;
const int M = 5.1e6 + 10;
int flag[M];
int cnt[M];
int a[N];
int pp[N];
int ans[M / 4];
vector<pair<int, int>> v[M];
vector<pair<int, int>> qr[N];
class BIT {
 public:
  int a[N];
  BIT() { memset((a), (0x3f), sizeof(a)); }
  inline int lowbit(int x) { return x & -x; }
  void add(int x, int y) {
    while (x < N) {
      a[x] = min(a[x], y);
      x += lowbit(x);
    }
  }
  int sum(int x) {
    int ret = INF;
    while (x) {
      ret = min(ret, a[x]);
      x -= lowbit(x);
    }
    return ret;
  }
} b;
void init() {
  for (int i = 1; i < M; i++) flag[i] = i;
  for (int i = 2; i < M; i++) {
    if (cnt[i] || flag[i] != i) continue;
    for (int j = i; j < M; j += i) {
      while (flag[j] % (1LL * i * i) == 0) flag[j] /= 1LL * i * i;
      if (flag[j] % i == 0) cnt[j]++;
    }
  }
  pp[0] = 1;
}
int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
void write(int x) {
  int y = 10, len = 1;
  while (y <= x) {
    y *= 10;
    len++;
  }
  while (len--) {
    y /= 10;
    putchar(x / y + 48);
    x %= y;
  }
}
int main() {
  init();
  int n, q;
  n = read();
  q = read();
  for (int i = 1; i <= n; i++) {
    int x;
    x = read();
    a[i] = flag[x];
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    l = read();
    r = read();
    qr[l].push_back({r, i});
  }
  for (int i = n; i >= 1; i--) {
    int x = a[i];
    int k = 0;
    for (int j = 2; j * j <= x; j++) {
      if (x % j) continue;
      x /= j;
      pp[1 << k] = j;
      k++;
    }
    if (x > 1) pp[1 << (k++)] = x;
    x = a[i];
    for (int o = 0; o < (1 << k); o++) {
      pp[o] = pp[o - (o & -o)] * pp[o & -o];
      int c = cnt[x / pp[o]];
      auto &vp = v[pp[o]];
      for (auto p : vp) {
        int val, pos;
        tie(val, pos) = p;
        b.add(pos, c + val);
      }
      while (!vp.empty() && make_pair(c, i) < vp.back()) vp.pop_back();
      vp.push_back({c, i});
    }
    for (auto &p : qr[i]) {
      int y, pos;
      tie(y, pos) = p;
      ans[pos] = b.sum(y);
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
