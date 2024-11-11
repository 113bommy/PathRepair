#include <bits/stdc++.h>
using namespace std;
decltype(0) main() {
  long long n, p;
  cin >> n >> p;
  priority_queue<pair<long long, pair<long long, long long>>,
                 std::vector<pair<long long, pair<long long, long long>>>,
                 std::greater<pair<long long, pair<long long, long long>>>>
      events;
  vector<long long> result(n);
  for (long long i = 0; i < n; i++) {
    long long pt;
    cin >> pt;
    events.push(make_pair(pt, make_pair(0, i)));
  }
  queue<long long> q;
  set<long long> qset;
  priority_queue<long long, vector<long long>, greater<long long>> awake;
  bool flag = false;
  while (!events.empty()) {
    pair<long long, pair<long long, long long>> curr = events.top();
    events.pop();
    if (curr.second.first == 0) {
      if (qset.lower_bound(curr.second.second) == qset.begin()) {
        q.push(curr.second.second);
        qset.insert(curr.second.second);
        if (!flag) {
          flag = true;
          events.push(
              make_pair(curr.first + p, make_pair(1, curr.second.second)));
        }
      } else {
        awake.push(curr.second.second);
      }
    } else {
      result[curr.second.second] = curr.first;
      qset.erase(curr.second.second);
      q.pop();
      if (!awake.empty() && qset.lower_bound(awake.top()) == qset.begin()) {
        q.push(awake.top());
        qset.insert(awake.top());
        awake.pop();
      }
      if (q.empty()) {
        flag = false;
      } else {
        events.push(make_pair(curr.first + p, make_pair(1, q.front())));
      }
    }
  }
  for (auto &i : result) {
    cout << i << " ";
  }
  cout << endl;
}
