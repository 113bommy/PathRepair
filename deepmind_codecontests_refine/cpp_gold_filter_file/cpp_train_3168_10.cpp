#include <bits/stdc++.h>
const int N = 4e6 + 10;
const int Inf = 0x3f3f3f3f;
using namespace std;
int Read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
const int V = 4000009;
long long nm[2], tr[2][2][V];
int lowbit(int x) { return x & -x; }
void Add(int idx1, int idx2, long long val) {
  for (int x = idx2 + 1; x <= nm[idx1]; x += lowbit(x))
    tr[idx1][0][x] += val * idx2, tr[idx1][1][x] += val;
}
long long Query(int idx1, int idx2) {
  long long res = 0;
  for (int x = ++idx2; x > 0; x -= lowbit(x))
    res += tr[idx1][1][x] * idx2 - tr[idx1][0][x];
  return res;
}
int main() {
  long long w, t, x1, y1, x2, y2, v;
  nm[0] = Read();
  nm[1] = Read();
  w = Read();
  while (w--) {
    t = Read();
    x1 = Read();
    y1 = Read();
    x2 = Read();
    y2 = Read();
    --x1, --y1;
    if (!t) {
      scanf("%I64d", &v);
      Add(0, x1, (y2 - y1) * v);
      Add(0, x2, (y1 - y2) * v);
      Add(1, y1, (x2 - x1) * v);
      Add(1, y2, (x1 - x2) * v);
    } else {
      --x2, --y2;
      long long part1 = Query(0, x2) - Query(0, x1 - 1);
      long long part2 = Query(1, y1 - 1);
      long long part3 = Query(1, nm[1] - 1) - Query(1, y2);
      printf("%I64d\n", part1 - part2 - part3);
    }
  }
  return 0;
}
void fastInOut() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
}
