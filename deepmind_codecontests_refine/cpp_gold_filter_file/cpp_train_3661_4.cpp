#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  int a[n];
  deque<int> dq;
  int idx = 0, val = 0;
  for (long long i = (0); i < (n); ++i) {
    cin >> a[i];
    if (a[i] > val) {
      val = a[i];
      idx = i;
    }
    dq.push_back(a[i]);
  }
  if (q == 0) return 0;
  int c = 0;
  vector<pair<int, int> > vec;
  while (true) {
    c++;
    int u = dq.front();
    dq.pop_front();
    int v = dq.front();
    vec.push_back({u, v});
    dq.pop_front();
    dq.push_front(max(u, v));
    dq.push_back(min(u, v));
    if (dq.front() == val) break;
  }
  auto it = dq.begin();
  it++;
  vector<int> rem;
  while (it != dq.end()) {
    rem.push_back(*it);
    it++;
  }
  while (q--) {
    long long m;
    cin >> m;
    if (m <= c)
      cout << vec[m - 1].first << " " << vec[m - 1].second << endl;
    else {
      m -= c;
      m %= rem.size();
      if (m == 0) m = rem.size();
      cout << val << " " << rem[m - 1] << endl;
    }
  }
  return 0;
}
