#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, p;
int t[100010];
long long ans[100010];
struct event {
  long long time;
  int type, index;
  event(long long t, int type, int id) : time(t), type(type), index(id) {}
};
struct cmp {
  bool operator()(event a, event b) {
    if (a.time == b.time) {
      if (a.type == b.type) {
        return a.index > b.index;
      }
      return a.type > b.type;
    }
    return a.time > b.time;
  }
};
priority_queue<event, vector<event>, cmp> PQ;
priority_queue<int, vector<int>, greater<int> > Wait;
queue<int> Q;
set<int> Q_min;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    PQ.push(event(t[i], 1, i));
  }
  long long cur_time = 0;
  while (!PQ.empty()) {
    event cur_event = PQ.top();
    PQ.pop();
    if (cur_event.type == 0) {
      Q_min.erase(Q.front());
      Q.pop();
      cur_time = cur_event.time;
      ans[cur_event.index] = cur_time;
      if (!Q.empty()) {
        PQ.push(event(cur_time + p, 0, Q.front()));
      } else if (!Wait.empty()) {
        PQ.push(event(cur_time, 1, Wait.top()));
        Wait.pop();
      }
    } else {
      if (Q.empty() || cur_event.index < *(Q_min.begin())) {
        if (Q.empty()) {
          PQ.push(event(cur_time + p, 0, cur_event.index));
        }
        Q.push(cur_event.index);
        Q_min.insert(cur_event.index);
      } else {
        Wait.push(cur_event.index);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
