#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000;
const int maxp = 1000000009;
int Nextint() {
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  int x = 0;
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
int N, M;
struct T {
  int x, y;
  friend bool operator<(const T &a, const T &b) { return a.x < b.x; }
} sq[maxn];
int gen;
struct T1 {
  int l, r, ans1, ans0, c1, c0;
  int lef, rig;
} opt[maxn];
int BLD(int l, int r) {
  if (l > r) return 0;
  int mx = l;
  for (int i = l + 1; i <= r; i++)
    if (sq[mx].y < sq[i].y) mx = i;
  opt[mx].l = sq[l].x;
  opt[mx].r = sq[r].x;
  opt[mx].lef = BLD(l, mx - 1);
  opt[mx].rig = BLD(mx + 1, r);
  opt[mx].ans0 = opt[opt[mx].lef].ans1 + opt[opt[mx].rig].ans1;
  opt[mx].ans1 = max(opt[opt[mx].lef].ans1 + opt[opt[mx].rig].ans0,
                     opt[opt[mx].lef].ans0 + opt[opt[mx].rig].ans1) +
                 1;
  if (opt[mx].ans1 < opt[mx].ans0) opt[mx].ans1 = opt[mx].ans0;
  return mx;
}
void Sol(int gen, int l, int r) {
  if (opt[gen].l >= l && opt[gen].r <= r) {
    opt[gen].c1 = opt[gen].ans1;
    opt[gen].c0 = opt[gen].ans0;
    return;
  }
  if (opt[gen].r < l || opt[gen].l > r) {
    opt[gen].c0 = -1;
    opt[gen].c1 = 0;
    return;
  }
  if (l > sq[gen].x) {
    Sol(opt[gen].rig, l, r);
    opt[gen].c1 = opt[opt[gen].rig].c1;
    opt[gen].c0 = opt[opt[gen].rig].c0;
    return;
  }
  if (r < sq[gen].x) {
    Sol(opt[gen].lef, l, r);
    opt[gen].c1 = opt[opt[gen].lef].c1;
    opt[gen].c0 = opt[opt[gen].lef].c0;
    return;
  }
  Sol(opt[gen].lef, l, r);
  Sol(opt[gen].rig, l, r);
  opt[gen].c0 = opt[opt[gen].lef].c1 + opt[opt[gen].rig].c1;
  opt[gen].c1 = max(opt[opt[gen].lef].c1 + opt[opt[gen].rig].c0,
                    opt[opt[gen].lef].c0 + opt[opt[gen].rig].c1) +
                1;
}
int main() {
  N = Nextint();
  M = Nextint();
  opt[0].r = opt[0].l = -int(1E9);
  opt[0].ans0 = opt[0].c0 = -1;
  for (int i = 1; i <= M; i++) sq[i].x = Nextint(), sq[i].y = Nextint();
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  for (int i = M + 1; i <= N; i++) {
    sq[i].x = (a * sq[i - 1].x + b) % maxp;
    sq[i].y = (c * sq[i - 1].y + d) % maxp;
  }
  sort(sq + 1, sq + N + 1);
  gen = BLD(1, N);
  M = Nextint();
  for (int i = 1; i <= M; i++) {
    int L = Nextint(), R = Nextint();
    Sol(gen, L, R);
    printf("%d\n", opt[gen].c1);
  }
  return 0;
}
