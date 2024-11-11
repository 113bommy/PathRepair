#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 100000;
int h, w, n, want;
bool haveret;
char ret[MAXN + 1], nret[MAXN + 1];
void bf() {
  for (int msk = (0); msk < (1 << n); ++msk) {
    int cur = 0;
    for (int x = (0); x < (h - 1); ++x)
      for (int y = (0); y < (w - 1); ++y) {
        int cnt = 0;
        for (int dx = (0); dx < (2); ++dx)
          for (int dy = (0); dy < (2); ++dy)
            if ((msk >> ((x + dx) * w + (y + dy))) & 1) ++cnt;
        if (cnt == 3) ++cur;
        if (cnt == 4) cur += 4;
      }
    if (cur == want) {
      haveret = true;
      for (int j = (0); j < (n); ++j) ret[j] = (msk >> j) & 1 ? '*' : '.';
      return;
    }
  }
}
void greedy() {
  if (h == 2 && want == (w - 2) * 4) {
    haveret = true;
    for (int x = (0); x < (h); ++x)
      for (int y = (0); y < (w); ++y)
        ret[x * w + y] = 0 <= y && y < w - 1 ? '*' : '.';
    return;
  }
  if (h == 2 && want == (w - 3) * 4) {
    haveret = true;
    for (int x = (0); x < (h); ++x)
      for (int y = (0); y < (w); ++y)
        ret[x * w + y] = 1 <= y && y < w - 1 ? '*' : '.';
    return;
  }
  if (h == 3 && want == (w - 2) * 8) {
    haveret = true;
    for (int x = (0); x < (h); ++x)
      for (int y = (0); y < (w); ++y)
        ret[x * w + y] = 0 <= y && y < w - 1 ? '*' : '.';
    return;
  }
  int left = want;
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y) ret[x * w + y] = x == 0 ? '*' : '.';
  int x, y;
  for (x = 1; x < h; ++x) {
    for (y = 0; y < w; ++y) {
      if (left <= 3 || x == h - 1 && w - y == 4) break;
      ret[x * w + y] = '*';
      left -= y == 0 ? 1 : y == w - 1 ? 3 : 4;
    }
    if (left <= 3 || x == h - 1 && w - y == 4) break;
  }
  if (x == h - 1 && w - y == 4) {
    for (int msk = (0); msk < (1 << 4); ++msk) {
      int cur = 0;
      for (int yy = (0); yy < (4); ++yy) {
        int cnt = 0;
        for (int dy = (0); dy < (2); ++dy)
          if (yy + dy == 0 || (msk >> (yy + dy - 1) & 1)) ++cnt;
        if (cnt == 1) ++cur;
        if (cnt == 2) cur += 4;
      }
      if (cur - 1 == left) {
        haveret = true;
        for (int j = (0); j < (4); ++j)
          ret[x * w + y + j] = (msk >> j) & 1 ? '*' : '.';
        return;
      }
    }
  }
  if (left <= 3) {
    int dy = w - y;
    int y1 = dy == 2 || dy >= 4 ? w - 1 : 0;
    int y2 = dy == 3 ? w - 2 : dy >= 4 ? w - 3 : dy == 2 ? 1 : 2;
    if (left & 1) ret[(x + (y1 < y ? 1 : 0)) * w + y1] = '*';
    if (left & 2) ret[(x + (y2 < y ? 1 : 0)) * w + y2] = '*';
    haveret = true;
  }
}
void run() {
  scanf("%d%d%d", &h, &w, &want);
  n = h * w;
  haveret = false;
  if (h <= 4 && w <= 4) {
    bf();
  } else {
    bool swp = w < h;
    if (swp) swap(w, h);
    greedy();
    if (swp) {
      swap(w, h);
      for (int x = (0); x < (h); ++x)
        for (int y = (0); y < (w); ++y) nret[x * w + y] = ret[y * h + x];
      for (int i = (0); i < (n); ++i) ret[i] = nret[i];
    }
  }
  if (!haveret)
    printf("-1\n");
  else
    for (int x = (0); x < (h); ++x) {
      for (int y = (0); y < (w); ++y) printf("%c", ret[x * w + y]);
      puts("");
    }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) {
    if (i != 1) puts("");
    run();
  }
  return 0;
}
