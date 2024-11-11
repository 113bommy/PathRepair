#include <bits/stdc++.h>
using namespace std;
struct turn {
  int me, you, idx;
  turn(){};
  turn(int me, int you, int idx) {
    this->me = me;
    this->you = you;
    this->idx = idx;
  }
};
int N;
int used[1 << 21];
char a[1 << 21], b[1 << 21];
turn ab[1 << 21], ba[1 << 21];
void scan() {
  scanf("%d", &N);
  scanf("%s%s", a, b);
}
inline int f(const turn &t1, const turn &t2) {
  return (t1.me * 2 + t1.you) > (t2.me * 2 + t1.you);
}
int winner() {
  for (int i = 0; i < N; ++i)
    if (a[i] > b[i])
      return 0;
    else if (b[i] > a[i])
      return 1;
  return 2;
}
void solve() {
  for (int i = 0; i < 2 * N; ++i) {
    ab[i] = turn(a[i] - '0', b[i] - '0', i);
    ba[i] = turn(b[i] - '0', a[i] - '0', i);
  }
  sort(ab, ab + 2 * N, f);
  sort(ba, ba + 2 * N, f);
  int idx1 = 0, idx2 = 0;
  for (int i = 0; i < N; ++i) {
    while (used[ab[idx1].idx]) ++idx1;
    a[i] = ab[idx1].me;
    used[ab[idx1].idx] = 1;
    while (used[ba[idx2].idx]) ++idx2;
    b[i] = ba[idx2].me;
    used[ba[idx2].idx] = 1;
  }
  int ans = winner();
  if (ans == 0)
    printf("First\n");
  else if (ans == 1)
    printf("Second\n");
  else
    printf("Draw\n");
}
int main() {
  scan();
  solve();
}
