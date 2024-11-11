#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
int n, p[N], q[N], idx[N];
bool op[N], cl[N];
struct br {
  int open, close;
  br() { open = close = 0; }
};
br seg[4 * N];
void update(int n, int s, int e, int at) {
  if (s > at || e < at) return;
  if (s == e) {
    seg[n].open = op[at];
    seg[n].close = cl[at];
    if (seg[n].open == seg[n].close) {
      seg[n].open = seg[n].close = 0;
    }
    return;
  }
  update(2 * n, s, (s + e) / 2, at);
  update(2 * n + 1, (s + e) / 2 + 1, e, at);
  int match = min(seg[2 * n].open, seg[2 * n + 1].close);
  seg[n].open = seg[2 * n].open + seg[2 * n + 1].open - match;
  seg[n].close = seg[2 * n].close + seg[2 * n + 1].close - match;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    idx[p[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &q[i]);
  }
  int answer = n;
  printf("%d", answer);
  for (int i = 1; i <= n - 1; ++i) {
    cl[q[i]] = 1;
    update(1, 1, n, q[i]);
    while (seg[1].open <= 0 && answer > 0) {
      op[idx[answer]] = 1;
      update(1, 1, n, idx[answer]);
      if (seg[1].open > 0) {
        op[idx[answer]] = 0;
        update(1, 1, n, idx[answer]);
        break;
      }
      answer--;
    }
    printf(" %d", answer);
  }
  puts("");
  return 0;
}
