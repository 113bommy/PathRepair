#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = (int)1e5 + 100;
const int M = (int)2e6 + 100;
const int inf = (int)1e8 + 100;
bool sss(pair<int, pair<long long, int> > x,
         pair<int, pair<long long, int> > y) {
  if (x.first == y.first) return x.second < y.second;
  return x.first > y.first;
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, m, i;
  cin >> n >> k >> m;
  set<pair<long long, pair<int, int> > > drive;
  set<pair<int, pair<long long, int> > > wait_up;
  set<pair<int, pair<long long, int> >,
      bool (*)(pair<int, pair<long long, int> >,
               pair<int, pair<long long, int> >)>
      wait_down(sss);
  for ((i) = 0; (i) < (k); (i)++) {
    int x;
    cin >> x;
    wait_up.insert({x, {0, i + 1}});
    wait_down.insert({x, {0, i + 1}});
  }
  long long cur_t = 0;
  for ((i) = 0; (i) < (m); (i)++) {
    long long t;
    int a, b;
    cin >> t >> a >> b;
    cur_t = max(t, cur_t);
    while (drive.size() && drive.begin()->first <= cur_t) {
      pair<long long, pair<int, int> > x = *drive.begin();
      drive.erase(x);
      wait_up.insert({x.second.second, {x.first, x.second.first}});
      wait_down.insert({x.second.second, {x.first, x.second.first}});
    }
    if (!wait_up.size()) {
      cur_t = max(drive.begin()->first, cur_t);
      while (drive.size() && drive.begin()->first <= cur_t) {
        pair<long long, pair<int, int> > x = *drive.begin();
        drive.erase(x);
        wait_up.insert({x.second.second, {x.first, x.second.first}});
        wait_down.insert({x.second.second, {x.first, x.second.first}});
      }
    }
    auto q = wait_up.lower_bound({a, {-1, -1}});
    auto w = wait_down.lower_bound({a, {-1, -1}});
    pair<int, pair<long long, int> > x;
    if (q != wait_up.end()) {
      if (w != wait_down.end()) {
        if (abs(a - q->first) == abs(b - q->first)) {
          if (q->second <= w->second) {
            x = *q;
          } else {
            x = *w;
          }
        } else {
          if (abs(a - q->first) < abs(b - q->first)) {
            x = *q;
          } else {
            x = *w;
          }
        }
      } else {
        x = *q;
      }
    } else {
      x = *w;
    }
    wait_up.erase(x);
    wait_down.erase(x);
    cout << x.second.second << ' ' << cur_t - t + abs(a - x.first) << '\n';
    drive.insert({cur_t + abs(a - x.first) + abs(a - b), {x.second.second, b}});
  }
}
