#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  deque<int> dq;
  int max_el = 0;
  for (int i = 0; i < (int)(n); ++i) {
    int x;
    cin >> x;
    max_el = max(max_el, x);
    dq.push_back(x);
  }
  int t = 1;
  map<int, pair<int, int> > steps;
  while (dq.front() != max_el) {
    int a = dq.front();
    dq.pop_front();
    int b = dq.front();
    dq.pop_front();
    steps[t++] = make_pair(a, b);
    if (a > b) {
      dq.push_front(a);
      dq.push_back(b);
    } else {
      dq.push_front(b);
      dq.push_back(a);
    }
  }
  while (q--) {
    long long m;
    cin >> m;
    if (m <= t) {
      cout << steps[m].first << ' ' << steps[m].second << ' ';
      cout << '\n';
    } else {
      m -= (t - 1);
      m %= (n - 1);
      if (m == 0) m = n - 1;
      cout << max_el << ' ' << dq[m] << ' ';
      cout << '\n';
    }
  }
  return 0;
}
