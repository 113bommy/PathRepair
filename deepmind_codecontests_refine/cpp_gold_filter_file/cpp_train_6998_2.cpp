#include <bits/stdc++.h>
using namespace std;
int bitsum[256];
int calcbitsum(int n) {
  int sum = 0;
  while (bitsum[n] == -1) {
    sum += n & 1;
    n >>= 1;
  }
  return sum + bitsum[n];
}
void initbitsum() {
  for (int i = 0; i < 256; ++i) {
    bitsum[i] = -1;
  }
  bitsum[0] = 0;
  for (int i = 0; i < 256; ++i) {
    bitsum[i] = calcbitsum(i);
  }
}
int main() {
  initbitsum();
  int n, m, k;
  cin >> n >> m >> k;
  pair<int, int *> from[n], to[n];
  for (int i = 0; i < n; ++i) {
    cin >> from[i].first >> to[i].first;
    ++to[i].first;
    from[i].second = to[i].second = new int(to[i].first);
  }
  sort(from, from + n);
  sort(to, to + n);
  int wall[8];
  for (int i = 0; i < 8; ++i) {
    wall[i] = 0;
  }
  unsigned char cur_cont = 0, next_cont = 0, cur_empty = UCHAR_MAX,
                next_empty = UCHAR_MAX;
  int *cur_best = new int[256], *next_best = new int[256];
  for (int i = 0; i < 256; ++i) {
    cur_best[i] = 0;
    next_best[i] = 0;
  }
  int prev_pos = 0, delta = 0;
  for (int i = 0, j = 0; i < n || j < n;) {
    int pos =
        (i == n ? to[j].first
                : (j == n ? from[i].first : min(from[i].first, to[j].first)));
    swap(cur_best, next_best);
    cur_empty = next_empty;
    cur_cont = next_cont;
    next_empty = 0;
    next_cont = 0;
    delta = pos - prev_pos;
    prev_pos = pos;
    for (; j < n && to[j].first == pos; ++j) {
      next_empty |= (1 << *to[j].second);
      next_cont |= (1 << *to[j].second);
    }
    for (; i < n && from[i].first == pos; ++i) {
      int &cur_from = from[i].first;
      int best = -1;
      for (int l = 0; l < 8; ++l) {
        if (cur_from >= wall[l] &&
            (best == -1 || cur_from - wall[best] > cur_from - wall[l])) {
          best = l;
        }
      }
      wall[best] = *from[i].second;
      *from[i].second = best;
      next_empty &= (UCHAR_MAX ^ (1 << best));
      next_cont |= (1 << best);
    }
    next_cont = ~next_cont;
    next_empty |= next_cont & cur_empty;
    for (int l = 0; l < 256; ++l) {
      next_best[l] = 0;
      if (l & cur_empty) {
        continue;
      }
      next_best[l] = cur_best[l & cur_cont] + delta * (bitsum[l] & 1);
      next_best[l & next_cont] = max(next_best[l], next_best[l & next_cont]);
    }
  }
  cout << next_best[0];
}
