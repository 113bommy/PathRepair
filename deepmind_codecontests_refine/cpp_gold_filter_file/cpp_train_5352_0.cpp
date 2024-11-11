#include <bits/stdc++.h>
using namespace std;
deque<int> pos[100010];
deque<int> diff[100010];
int cnt_occ[100010] = {0};
int cnt_period[100010] = {0};
int cnt_valid = 0;
int cnt_distinct = 0;
int a[100010];
int l[100010], r[100010];
pair<pair<int, int>, int> query[100010];
int ans[100010];
void add(int i, int val, bool f) {
  if (cnt_occ[val] >= 2) {
    int cur_diff = abs((f ? pos[val].back() : pos[val].front()) - i);
    int prev_diff = (f ? diff[val].back() : diff[val].front());
    if (cur_diff != prev_diff) {
      cnt_period[val]++;
      if (cnt_period[val] == 2) cnt_valid--;
    }
    if (!f)
      diff[val].push_front(cur_diff);
    else
      diff[val].push_back(cur_diff);
  } else if (cnt_occ[val] == 1) {
    int cur_diff = abs((f ? pos[val].back() : pos[val].front()) - i);
    diff[val].push_back(cur_diff);
    cnt_period[val]++;
  } else
    cnt_valid++;
  if (!f)
    pos[val].push_front(i);
  else
    pos[val].push_back(i);
  cnt_occ[val]++;
  if (cnt_occ[val] == 1) cnt_distinct++;
}
void rem(int i, int val, bool f) {
  if (cnt_occ[val] >= 3) {
    int cur_diff = (f ? diff[val].back() : diff[val].front());
    if (!f)
      diff[val].pop_front();
    else
      diff[val].pop_back();
    int prev_diff = (f ? diff[val].back() : diff[val].front());
    if (cur_diff != prev_diff) {
      cnt_period[val]--;
      if (cnt_period[val] == 1) cnt_valid++;
    }
  } else if (cnt_occ[val] == 2) {
    diff[val].pop_back();
    cnt_period[val]--;
  } else
    cnt_valid--;
  if (!f)
    pos[val].pop_front();
  else
    pos[val].pop_back();
  cnt_occ[val]--;
  if (cnt_occ[val] == 0) cnt_distinct--;
}
int main() {
  int n, q, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d", &a[i]);
  int block = sqrt(n);
  scanf("%d", &q);
  for (i = 0; i < q; ++i) {
    scanf("%d", &l[i]);
    scanf("%d", &r[i]);
    --l[i];
    --r[i];
    query[i] = make_pair(make_pair(l[i] / block, r[i]), i);
  }
  sort(query, query + q);
  int p1 = 0, p2 = -1;
  for (j = 0; j < q; ++j) {
    i = query[j].second;
    while (p1 > l[i]) {
      --p1;
      add(p1, a[p1], 0);
    }
    while (p2 < r[i]) {
      ++p2;
      add(p2, a[p2], 1);
    }
    while (p1 < l[i]) {
      rem(p1, a[p1], 0);
      ++p1;
    }
    while (p2 > r[i]) {
      rem(p2, a[p2], 1);
      --p2;
    }
    ans[i] = cnt_distinct;
    if (!cnt_valid) ans[i]++;
  }
  for (i = 0; i < q; ++i) cout << ans[i] << '\n';
}
