#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m), p(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  for (auto &x : p) cin >> x;
  vector<int> suff(n);
  suff[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) suff[i] = max(suff[i + 1], a[i]);
  set<pair<int, int> > event;
  for (int i = 0; i < m; i++) {
    if (b[i] <= suff[0])
      event.insert(
          {-n + 1 +
               (lower_bound(suff.rbegin(), suff.rend(), b[i]) - suff.rbegin()),
           i});
  }
  priority_queue<int> done;
  long long int TOT = a[0];
  int res = 0, pos = 0;
  for (auto e : event) {
    int x = e.second;
    while (pos < -e.first) {
      TOT += a[++pos];
    }
    if (p[x] <= TOT) {
      TOT -= p[x];
      res++;
      done.push(p[x]);
    } else if (!done.empty()) {
      if (done.top() <= p[x]) continue;
      TOT += done.top() - p[x];
      done.pop();
      done.push(p[x]);
    }
  }
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    test_case();
  }
  return 0;
}
