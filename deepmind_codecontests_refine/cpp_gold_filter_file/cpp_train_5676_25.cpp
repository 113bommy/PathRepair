#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
int n, a, cf, cm;
long long m;
pair<int, int> seq[N];
int group_cnt;
int group_start[N];
long long group_cost[N];
int res[N];
void solve() {
  scanf("%d%d%d%d%lld", &n, &a, &cf, &cm, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &seq[i].first);
    seq[i].second = i;
  }
  sort(seq, seq + n);
  group_cnt = 1;
  int pos = 0;
  for (int i = 1; i < n; i++)
    if (seq[i].first != seq[pos].first) {
      group_cost[group_cnt - 1] +=
          (long long)i * (seq[i].first - seq[pos].first);
      group_cost[group_cnt] = group_cost[group_cnt - 1];
      group_start[group_cnt] = i;
      group_cnt++;
      pos = i;
    }
  long long now_m = m;
  long long best_score = -1;
  int best_i = -1;
  int best_minima = -1;
  for (int i = n; i >= 0; i--) {
    if (i < n) now_m -= a - seq[i].first;
    if (now_m < 0) break;
    long long score = (long long)cf * (n - i);
    int minima = -1;
    if (i > 0) {
      int last_group =
          upper_bound(group_start, group_start + group_cnt, i - 1) -
          group_start - 1;
      int left = -1, right = last_group;
      while (right - left > 1) {
        int mid = (left + right) / 2;
        if (group_cost[mid] <= now_m)
          left = mid;
        else
          right = mid;
      }
      long long left_now_m = now_m;
      if (left >= 0) left_now_m -= group_cost[left];
      minima = seq[group_start[right]].first;
      int size, max_cnt;
      if (right == last_group) {
        size = i;
        max_cnt = a - seq[i - 1].first;
      } else {
        size = group_start[right + 1];
        max_cnt =
            seq[group_start[right + 1]].first - seq[group_start[right]].first;
      }
      minima += (int)min((long long)max_cnt, left_now_m / size);
    } else
      minima = a;
    score += (long long)cm * minima;
    if (score > best_score) {
      best_score = score;
      best_i = i;
      best_minima = minima;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i < best_i)
      res[seq[i].second] = max(best_minima, seq[i].first);
    else
      res[seq[i].second] = a;
  }
  printf("%lld\n", best_score);
  for (int i = 0; i < n; i++) printf("%d ", res[i]);
  printf("\n");
}
int main() {
  solve();
  0;
  return 0;
}
