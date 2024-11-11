#include <bits/stdc++.h>
using namespace std;
struct dat {
  long long x, y;
  dat(long long x = 0, long long y = 0) : x(x), y(y) {}
} p[1000000];
bool operator<(dat A, dat B) {
  if (A.x != B.x) return A.x < B.x;
  return A.y < B.y;
}
bool operator==(dat A, dat B) {
  if (A.x == B.x && A.y == B.y) return 1;
  return 0;
}
int main() {
  long long x;
  scanf("%I64d\n", &x);
  int cnt = 0;
  for (long long i = 1; i <= 1e6; i++) {
    if (6 * x % (i * (i + 1)) == 0) {
      long long y = 6 * x / i / (i + 1);
      if ((2 * i - 2) > y) continue;
      if ((y - 2 * i + 2) % 3) continue;
      long long z = (y - 2 * i + 2) / 3;
      long long j = i + z - 1;
      p[cnt++] = dat(i, j);
      p[cnt++] = dat(j, i);
    }
  }
  sort(p, p + cnt);
  cnt = unique(p, p + cnt) - p;
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) {
    printf("%I64d %I64d\n", p[i].x, p[i].y);
  }
}
