#include <bits/stdc++.h>
using namespace std;
int position_a[100005];
int permut_a[100005];
int permut_b[100005];
unsigned int min_round_dist[100005];
unsigned int min_round_left[100005];
unsigned int min_round_right[100005];
pair<int, int> round_limit[100005];
vector<int> zero_list;
deque<int> rq;
deque<int> lq;
int n, v;
inline int dist(int ap, int bp) {
  if (ap <= bp) return bp - ap;
  return n - (ap - bp);
}
inline int to_left(int pos, int step = 1) {
  return pos - step >= 0 ? pos - step : pos + n - step;
}
inline int to_right(int pos, int step = 1) {
  return pos + step < n ? pos + step : pos + step - n;
}
int main() {
  ios::sync_with_stdio(false);
  bool passed[100005];
  memset(min_round_dist, -1, sizeof(min_round_dist));
  memset(min_round_right, -1, sizeof(min_round_right));
  memset(min_round_left, -1, sizeof(min_round_left));
  memset(passed, 0, sizeof(passed));
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> permut_a[i];
    position_a[permut_a[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> permut_b[i];
    int d = dist(position_a[permut_b[i]], i);
    min_round_dist[d] = 0;
    if (position_a[permut_b[i]] <= i) {
      if (n - position_a[permut_b[i]] > round_limit[d].first)
        round_limit[d].first = n - position_a[permut_b[i]] - 1;
      if (position_a[permut_b[i]] > round_limit[d].second)
        round_limit[d].second = position_a[permut_b[i]];
    } else {
      if (n - position_a[permut_b[i]] > round_limit[d].first)
        round_limit[d].first = n - position_a[permut_b[i]] - 1;
      if (position_a[permut_b[i]] > round_limit[d].second)
        round_limit[d].second = position_a[permut_b[i]];
    }
  }
  for (int i = 0; i < n; ++i)
    if (min_round_dist[i] == 0) {
      zero_list.push_back(i);
      rq.push_front(i);
      lq.push_back(i);
    }
  for (int i = 0; i < n; ++i) {
    if (min_round_dist[i] != 0) {
      while (!rq.empty()) {
        int D = dist(rq.front(), i);
        if (D <= round_limit[rq.front()].second) {
          min_round_right[i] = D;
          break;
        } else
          rq.pop_front();
      }
    } else {
      if (rq.back() == i) rq.pop_back();
      rq.push_front(i);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (min_round_dist[i] != 0) {
      while (!rq.empty()) {
        int D = dist(i, lq.front());
        if (D <= round_limit[lq.front()].first) {
          min_round_left[i] = D;
          break;
        } else
          rq.pop_front();
      }
    } else {
      if (lq.back() == i) lq.pop_back();
      lq.push_front(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (min_round_dist[i] == 0)
      cout << 0 << endl;
    else {
      cout << min(min_round_left[i], min_round_right[i]) << endl;
    }
  }
}
