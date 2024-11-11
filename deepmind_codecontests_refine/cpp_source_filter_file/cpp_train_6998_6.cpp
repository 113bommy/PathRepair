#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
using namespace std;
const int maxn = 1e5 + 10;
struct event {
  int pos, add, id;
  event() {}
  event(int a, int b, int c) : pos(a), add(b), id(c) {}
  bool operator<(const event& rhs) const {
    if (pos != rhs.pos) return pos < rhs.pos;
    return add < rhs.add;
  }
} events[maxn << 1];
int N, K, M;
int DP[maxn << 1][1 << 8];
int mask[maxn << 1];
int bit_pos[maxn];
int bit_count[1 << 8];
int find_bit(int state) {
  int ret = 0;
  for (int i = 0; i < K; ++i) {
    if ((state & (1 << i)) == 0) {
      ret = i;
      break;
    }
  }
  return ret;
}
int main() {
  for (int state = 0; state < (1 << 8); ++state) {
    bit_count[state] = __builtin_popcount(state);
  }
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 1; i <= N; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    events[i] = event(l, 1, i);
    events[i + N] = event(r, -1, i);
  }
  sort(events + 1, events + 1 + 2 * N);
  int pre = 0;
  for (int i = 1; i <= 2 * N; ++i) {
    if (events[i].add == 1) {
      int ok_bit = find_bit(mask[i - 1]);
      mask[i] = mask[i - 1] | (1 << ok_bit);
      bit_pos[events[i].id] = ok_bit;
      for (int state = 0; state < (1 << K); ++state) {
        if ((state & mask[i - 1]) != state) continue;
        int dis = (bit_count[state] % 2) ? events[i].pos - pre : 0;
        DP[i][state | (1 << ok_bit)] =
            max(DP[i][state | (1 << ok_bit)], DP[i - 1][state] + dis);
        DP[i][state] = max(DP[i][state], DP[i - 1][state] + dis);
      }
    } else {
      int nok_bit = bit_pos[events[i].id];
      mask[i] = mask[i - 1] ^ (1 << nok_bit);
      for (int state = 0; state < (1 << K); ++state) {
        if ((state & mask[i - 1]) != state) continue;
        int dis = (bit_count[state] % 2) ? events[i].pos - pre : 0;
        if (state & (1 << nok_bit)) {
          DP[i][state ^ (1 << nok_bit)] =
              max(DP[i][state ^ (1 << nok_bit)], DP[i - 1][state] + dis);
        } else {
          DP[i][state] = max(DP[i][state], DP[i - 1][state] + dis);
        }
      }
    }
    pre = events[i].pos;
  }
  int ret = 0;
  for (int state = 0; state < (1 << K); ++state) {
    if ((state & mask[2 * N]) == state) {
      ret = max(ret, DP[2 * N][state]);
    }
  }
  printf("%d\n", ret);
}
