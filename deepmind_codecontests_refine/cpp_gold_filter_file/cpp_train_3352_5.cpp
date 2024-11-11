#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    q1;
priority_queue<long long, vector<long long>, greater<long long> > q2;
queue<long long> q3;
set<long long> emp;
long long ans[N];
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  long long n, c;
  cin >> n >> c;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    q1.push({x, i});
  }
  long long cur = 0;
  while (q1.size() || q2.size() || q3.size()) {
    if (q2.empty() && q3.empty()) cur = max(cur, q1.top().first);
    while (q1.size() && q1.top().first <= cur + c) {
      if (emp.empty() || (*emp.begin() > q1.top().second)) {
        q3.push(q1.top().second);
        emp.insert(q1.top().second);
      } else
        q2.push(q1.top().second);
      q1.pop();
    }
    if (q3.size()) {
      cur += c;
      ans[q3.front()] = cur;
      emp.erase(q3.front());
      q3.pop();
    }
    if (q2.size() && q3.empty()) {
      q3.push(q2.top());
      emp.insert(q2.top());
      q2.pop();
    }
  }
  for (long long i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
