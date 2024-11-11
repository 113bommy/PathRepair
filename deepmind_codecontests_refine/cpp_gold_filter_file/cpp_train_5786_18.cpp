#include <bits/stdc++.h>
using namespace std;
const int N = 16, Inf = 1e9;
static int n, sqrn, R, B, ans, lasts;
struct TCard {
  bool c;
  int r, b;
} card[N];
static int f[1 << N][N * N + 1][2], cardr[1 << N], cardb[1 << N];
inline int GetF(int s, int rem, bool c) {
  rem = min(rem, sqrn);
  if (s == lasts) return 0;
  auto &fs = f[s][rem][c];
  if (fs != -1) return fs;
  fs = Inf;
  for (int i = 0; i < n; ++i) {
    if (s & 1 << i) continue;
    int R = card[i].r - cardr[s], B = card[i].b - cardb[s], turn, _r, _b;
    if (c) {
      turn = max({0, R - rem, B});
      _r = rem + turn - max(R, 0);
      _b = turn - max(B, 0);
    } else {
      turn = max({0, B - rem, R});
      _b = rem + turn - max(B, 0);
      _r = turn - max(R, 0);
    }
    if (_r)
      fs = min(fs, turn + GetF(s ^ 1 << i, _r, 1));
    else
      fs = min(fs, turn + GetF(s ^ 1 << i, _b, 0));
  }
  return fs;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  sqrn = n * n;
  lasts = (1 << n) - 1;
  for_each(card, card + n, [](TCard &C) {
    char tmp;
    cin >> tmp >> C.r >> C.b;
    C.c = tmp == 'R';
    if (C.r > n) R += C.r - n, C.r = n;
    if (C.b > n) B += C.b - n, C.b = n;
  });
  for (int s = 1; s <= lasts; ++s) {
    int i = __builtin_ctz(s);
    cardr[s] = cardr[s ^ 1 << i] + card[i].c;
    cardb[s] = cardb[s ^ 1 << i] + !card[i].c;
  }
  memset(f, -1, sizeof f);
  if (R > B)
    ans = R + GetF(0, R - B, 0);
  else
    ans = B + GetF(0, B - R, 1);
  cout << ans + n;
  return 0;
}
