#include <bits/stdc++.h>
using namespace std;
struct event_t {
  int time;
  int change_incr_by;
  int change_sum_by;
  bool operator<(const event_t &other) const { return (time < other.time); }
};
const int max_N = 1e6 + 10;
int P[max_N];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", P + i);
  }
  vector<event_t> events;
  long long incr = 0, curr = 0;
  for (int i = 0; i < N; ++i) {
    int x = P[i] - 1;
    curr += abs(x - i);
    if (x <= i) {
      ++incr;
      events.push_back({N - i + x, 2, 0});
    } else {
      --incr;
      events.push_back({x - i, 2, 0});
    }
    events.push_back({N - 1 - i, -1, 0});
    events.push_back({N - i, -1, x - (N - 1 - x)});
  }
  sort(events.begin(), events.end());
  int i = 0;
  const long long inf = 1e17 + 42;
  long long min_dev = inf, point = -1;
  for (int k = 0; k < N; ++k) {
    while (i < events.size() && events[i].time == k) {
      incr += events[i].change_incr_by;
      curr += events[i].change_sum_by;
      ++i;
    }
    if (tie(min_dev, point) > tie(curr, k)) {
      tie(min_dev, point) = tie(curr, k);
    }
    curr += incr;
  }
  cout << min_dev << ' ' << point << endl;
}
