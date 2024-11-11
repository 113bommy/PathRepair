#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct event_t {
  long long t;
  int type, id;
  bool operator<(const event_t &o) const {
    return tie(t, type, id) > tie(o.t, o.type, id);
  }
};
long long a[N], ans[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p;
  set<int> active, in_queue;
  priority_queue<event_t> events;
  long long queue_free_at = 0;
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    events.push({a[i], 0, i});
  }
  while (!events.empty()) {
    auto cur = events.top();
    events.pop();
    if (cur.type == 0) {
      active.insert(cur.id);
    } else {
      in_queue.erase(cur.id);
    }
    while (!active.empty()) {
      int id = *active.begin();
      if (in_queue.empty() or id < *in_queue.begin()) {
        queue_free_at = max(queue_free_at, a[id]) + p;
        ans[id] = queue_free_at;
        active.erase(id);
        in_queue.insert(id);
        events.push({ans[id], 1, id});
      } else {
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}
