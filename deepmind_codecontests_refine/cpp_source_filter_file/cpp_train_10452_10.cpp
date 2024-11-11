#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  register int ret = 0;
  while (!(ch >= '0' && ch <= '9')) ch = getchar();
  while (ch >= '0' && ch <= '9')
    ret = (ret << 3) + (ret << 1) + (ch ^ 48), ch = getchar();
  return ret;
}
const int maxn = 100010;
struct Task {
  int id;
  int bai, man;
} ts[maxn];
Task part1[maxn];
Task part2[maxn];
int cnt2 = 0;
int n, p, k;
bool cmp1(const Task &a, const Task &b) {
  if (a.man == b.man) {
    return a.bai > b.bai;
  } else {
    return a.man < b.man;
  }
}
bool cmp2(const Task &a, const Task &b) {
  if (a.bai == b.bai) {
    return a.man > b.man;
  } else {
    return a.bai > b.bai;
  }
}
bool cmp3(const Task &a, const Task &b) { return a.man > b.man; }
int minman = 0x3f3f3f3f;
int main() {
  n = read();
  p = read();
  k = read();
  for (register int i = 1; i <= n; i++) {
    ts[i].bai = read();
    ts[i].man = read();
    ts[i].id = i;
  }
  sort(ts + 1, ts + 1 + n, cmp1);
  for (register int i = 1; i <= n - (p - k); i++) {
    part1[i] = ts[n - i + 1];
  }
  sort(part1 + 1, part1 + 1 + n - (p - k), cmp2);
  for (register int i = 1; i <= k; i++) {
    printf("%d ", part1[i].id);
    minman = min(part1[i].man, minman);
  }
  for (register int i = 1; i <= (p - k); i++) {
    part2[++cnt2] = ts[i];
  }
  for (register int i = k + 1; i <= n - (p - k); i++) {
    if (part1[i].man <= minman) part2[++cnt2] = part1[i];
  }
  sort(part2 + 1, part2 + 1 + cnt2, cmp3);
  for (register int i = 1; i <= p - k; i++) {
    printf("%d ", part2[i].id);
  }
  return 0;
}
