#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e12;
struct Event {
  long long l;
  long long r;
  long long cost;
  Event() {}
  Event(long long l, long long r, long long cost) : l(l), r(r), cost(cost) {}
  bool operator<(const Event &x) const {
    return l < x.l || l == x.l && r < x.r;
  }
  friend istream &operator>>(istream &in, Event &x) {
    in >> x.l >> x.r >> x.cost;
    return in;
  }
};
bool cmp(pair<Event, int> &a, pair<Event, int> &b) {
  if (a.second && b.second) return a.first.r < b.first.r;
  if (!a.second && !b.second) return a.first.l < b.first.l;
  if (!a.second && b.second) return a.first.l <= b.first.r;
  return a.first.r < b.first.l;
}
vector<pair<Event, int>> ev;
array<long long, 200500> pr;
int main() {
  ios::sync_with_stdio(false);
  long long n, x;
  cin >> n >> x;
  ev.resize(2 * n);
  pr.fill(2 * INF);
  for (int i = 0; i < n; i++) {
    cin >> ev[i].first;
    ev[i + n].first = ev[i].first;
    ev[i].second = 0;
    ev[i + n].second = 1;
  }
  sort(ev.begin(), ev.end(), cmp);
  long long ans = INF;
  for (int i = 0; i < 2 * n; i++) {
    if (!ev[i].second) {
      if (x - ev[i].first.r + ev[i].first.l - 1 >= 0)
        ans = min(ev[i].first.cost + pr[x - ev[i].first.r + ev[i].first.l - 1],
                  ans);
    } else {
      pr[ev[i].first.r - ev[i].first.l + 1] =
          min(pr[ev[i].first.r - ev[i].first.l + 1], ev[i].first.cost);
    }
  }
  if (ans == INF)
    cout << -1;
  else
    cout << ans;
  return 0;
}
