#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int ios = 1 << 17;
char R[ios], *Rc = R, *RB = R;
int pass;
inline int gec() {
  return (Rc == RB && (RB = (Rc = R) + fread(R, 1, ios, stdin), Rc == RB))
             ? EOF
             : *Rc++;
}
template <typename Tp>
inline int read(Tp& A) {
  static int c, sg;
  c = gec();
  sg = 0;
  A = 0;
  while (!isdigit(c) && c != EOF) sg |= (c == '-'), c = gec();
  if (c == EOF) return EOF;
  while (isdigit(c)) A = (A << 3) + (A << 1) + (c ^ '0'), c = gec();
  return A = sg ? -A : A, 0;
}
inline int read() { return read(pass), pass; }
}  // namespace IO
using IO::gec;
using IO::read;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
const int N = 1e2 + 5;
int a[N], b[N], r[2][N], x[N], y[N], ed[N], mov[N];
int n, k, lv, C;
struct Rp {
  int id, x, y;
} Que[20010];
void Move(int i, int dir) {
  Que[++C] = (Rp){i, x[i] += dx[dir], y[i] += dy[dir]};
}
void Run(int i) {
  if (mov[i] || !i) return;
  int dir = (x[i]) ? ((y[i] != 1) << 1) : ((y[i] != n) << 1 | 1);
  if (!r[x[i] + dx[dir]][y[i] + dy[dir]])
    mov[i] = 1, r[x[i]][y[i]] = 0, Move(i, dir), r[x[i]][y[i]] = i;
}
void Sit() {
  for (int i = 1; i <= k; i++) {
    if (!ed[i]) {
      if (x[i] & 1) {
        if (b[y[i]] == i) r[x[i]][y[i]] = 0, Move(i, 1), ed[i] = 1, lv++;
      } else {
        if (a[y[i]] == i) r[x[i]][y[i]] = 0, Move(i, 0), ed[i] = 1, lv++;
      }
    }
  }
}
void Row() {
  memset(mov, 0, sizeof(mov));
  for (int i = 1; i <= n; i++) Run(r[1][i]);
  for (int i = n; i >= 1; i--) Run(r[0][i]);
  for (int i = 1; i <= n; i++) Run(r[1][i]);
  for (int i = n; i >= 1; i--) Run(r[0][i]);
}
int main() {
  read(n);
  read(k);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1, id; i <= n; i++) read(id), r[x[id] = 0][y[id] = i] = id;
  for (int i = 1, id; i <= n; i++) read(id), r[x[id] = 1][y[id] = i] = id;
  for (int i = 1; i <= n; i++) read(b[i]);
  Sit();
  if (!lv && k == 2 * n) return puts("-1"), 0;
  while (lv < k) Row(), Sit();
  printf("%d\n", C);
  for (int i = 1; i <= C; i++)
    printf("%d %d %d\n", Que[i].id, Que[i].x, Que[i].y);
  return 0;
}
