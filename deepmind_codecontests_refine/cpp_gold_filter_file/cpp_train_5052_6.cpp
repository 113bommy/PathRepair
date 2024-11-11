#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
struct Event {
  long long time, length, id;
};
vector<Event> events;
long long ans[200005];
int main() {
  fill(ans, ans + 200005, -1);
  long long N, B;
  cin >> N >> B;
  for (long long i = 1; i <= N; i++) {
    long long t, d;
    cin >> t >> d;
    events.push_back({t, d, i});
  }
  events.push_back({INF, 1, N + 1});
  queue<pair<long long, long long>> q;
  long long time = 0;
  for (Event e : events) {
    while (!q.empty() && e.time >= time + q.front().first) {
      ans[q.front().second] = time + q.front().first;
      time += q.front().first;
      q.pop();
    }
    if (q.empty()) time = e.time;
    if (q.size() != B + 1) q.push({e.length, e.id});
  }
  for (long long i = 1; i <= N; i++) cout << ans[i] << " ";
}
