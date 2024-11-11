#include <bits/stdc++.h>
using namespace std;
int main() {
  int tests;
  cin >> tests;
  for (int test = 0; test < tests; ++test) {
    int n, total_time, a, b;
    cin >> n >> total_time >> a >> b;
    vector<int> simple;
    vector<int> hard;
    for (int i = 0; i < n; ++i) {
      int is_hard;
      cin >> is_hard;
      if (is_hard)
        hard.push_back(i);
      else
        simple.push_back(i);
    }
    vector<int> req_time(n);
    copy_n(istream_iterator<int>(cin), n, req_time.begin());
    sort(simple.begin(), simple.end(),
         [&](int l, int r) { return req_time[l] < req_time[r]; });
    sort(hard.begin(), hard.end(),
         [&](int l, int r) { return req_time[l] < req_time[r]; });
    int64_t penalty = 0;
    int req_cnt = 0;
    auto sit = simple.begin();
    auto hit = hard.begin();
    int max_cnt = 0;
    auto update_max = [&](int t) {
      if (t < penalty) return;
      int simple_cnt = min<int>((t - penalty) / a, simple.end() - sit);
      int hard_cnt =
          min<int>((t - penalty - simple_cnt * a) / b, hard.end() - hit);
      max_cnt = max(max_cnt, simple_cnt + hard_cnt + req_cnt);
    };
    while (true) {
      int t;
      if (sit != simple.end() && hit != hard.end())
        t = min(req_time[*sit], req_time[*hit]);
      else if (sit != simple.end())
        t = req_time[*sit];
      else if (hit != hard.end())
        t = req_time[*hit];
      else
        break;
      if (t != 0) update_max(t - 1);
      while (sit != simple.end() && req_time[*sit] == t) {
        penalty += a;
        ++sit;
        ++req_cnt;
      }
      while (hit != hard.end() && req_time[*hit] == t) {
        penalty += b;
        ++hit;
        ++req_cnt;
      }
    }
    update_max(total_time);
    cout << max_cnt << "\n";
  }
}
