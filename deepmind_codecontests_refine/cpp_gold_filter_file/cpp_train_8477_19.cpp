#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 42, BLOCK_SIZE = 500;
int n, banner;
pair<int, int> input[nmax];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
pair<int, long long> active[nmax / BLOCK_SIZE + 1][BLOCK_SIZE + 42];
int SZ[nmax];
int added[nmax];
long long current[nmax];
bool cover(pair<int, long long> le, pair<int, long long> test,
           pair<int, long long> ri) {
  long long up_1 = -(le.second - test.second);
  long long down_1 = -(test.first - le.first);
  long long up_2 = -(test.second - ri.second);
  long long down_2 = -(ri.first - test.first);
  assert(up_1 > 0);
  assert(down_1 > 0);
  assert(up_2 > 0);
  assert(down_2 > 0);
  return up_1 * down_2 <= up_2 * down_1;
}
void build(int current_block) {
  int beg_block = current_block * BLOCK_SIZE,
      end_block = current_block * BLOCK_SIZE + BLOCK_SIZE - 1;
  end_block = min(end_block, nmax - 1);
  SZ[current_block] = 0;
  long long MX = -1;
  for (int i = end_block; i >= beg_block; i--) {
    if (MX >= current[i]) continue;
    MX = current[i];
    SZ[current_block]++;
    active[current_block][SZ[current_block]] = {i, current[i]};
  }
  int up_to = SZ[current_block];
  SZ[current_block] = 1;
  for (int i = 2; i <= up_to; i++) {
    while (SZ[current_block] >= 2 &&
           cover(active[current_block][SZ[current_block] - 1],
                 active[current_block][SZ[current_block]],
                 active[current_block][i]))
      SZ[current_block]--;
    SZ[current_block]++;
    active[current_block][SZ[current_block]] = active[current_block][i];
  }
}
void update(int now) {
  int current_block = now / BLOCK_SIZE;
  for (int i = 0; i < current_block; i++) added[i]++;
  int beg_block = current_block * BLOCK_SIZE;
  int end_block = beg_block + BLOCK_SIZE - 1;
  end_block = min(end_block, nmax - 1);
  for (int i = beg_block; i <= end_block; i++) {
    current[i] += 1LL * i * added[current_block];
    if (i <= now) current[i] += i;
  }
  added[current_block] = 0;
  build(current_block);
}
pair<long long, int> query() {
  pair<long long, int> ret = {-1, -1};
  for (int i = 0; i * BLOCK_SIZE < nmax; i++)
    for (int j = 1; j <= SZ[i]; j++) {
      pair<long long, int> now = {
          1LL * added[i] * active[i][j].first + active[i][j].second,
          active[i][j].first};
      if (ret.first < now.first) {
        ret = now;
      }
    }
  return ret;
}
int main() {
  scanf("%i%i", &n, &banner);
  for (int i = 1; i <= n; i++) scanf("%i%i", &input[i].first, &input[i].second);
  for (int i = 0; i * BLOCK_SIZE < nmax; i++) build(i);
  sort(input + 1, input + n + 1, cmp);
  int id = 1;
  int mx = 0;
  for (int i = 1; i <= n; i++) mx = max(mx, input[i].second);
  mx++;
  for (int c = 0; c <= mx; c++) {
    while (id <= n && input[id].second < c) {
      update(input[id].first);
      id++;
    }
    pair<long long, int> now = query();
    now.first = now.first + 1LL * (n - id + 1) * c * banner;
    printf("%lld %i\n", now.first, now.second);
  }
  return 0;
}
