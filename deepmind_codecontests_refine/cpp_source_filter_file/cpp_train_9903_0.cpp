#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int job;
  int cost;
} Lazy;
auto main(int argc, char* argv[]) -> int {
  auto lv = vector<Lazy>();
  auto pq = map<int, priority_queue<int>>();
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    lv.push_back({0, 0});
    cin >> lv[i].job;
  }
  for (int i = 0; i < n; i++) cin >> lv[i].cost;
  for (int i = 0; i < n; i++) {
    auto j = lv[i].job;
    auto c = lv[i].cost;
    if (pq.find(j) == pq.end()) {
      pq[j] = priority_queue<int>();
      pq[j].push(c);
    } else
      pq[j].push(c);
  }
  auto vc = vector<int>();
  for (auto m : pq) {
    auto q = m.second;
    q.pop();
    while (!q.empty()) {
      vc.push_back(q.top());
      q.pop();
    }
  }
  sort(vc.begin(), vc.end());
  auto f = n - k;
  auto len = vc.size() - f;
  auto t = 0;
  for (int i = 0; i < len; i++) {
    t += vc[i];
  }
  cout << t << endl;
  return 0;
}
