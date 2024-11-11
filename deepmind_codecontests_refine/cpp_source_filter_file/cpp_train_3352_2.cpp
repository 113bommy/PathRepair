#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, p, t = 0, ch = 0;
  cin >> n >> p;
  vector<pair<long long, long long> > a;
  vector<long long> ans(n);
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(make_pair(x, i + 1));
  }
  sort(a.begin(), a.end());
  queue<int> Q;
  priority_queue<long long> q;
  while (ch < n || !q.empty()) {
    if (q.empty()) {
      Q.push(a[ch].second * (-1));
      t = a[ch].first;
      ch++;
    } else {
      int x = q.top() * (-1);
      q.pop();
      Q.push(x * (-1));
    }
    while (!Q.empty()) {
      int x = Q.front() * (-1);
      t += p;
      ans[x - 1] = t;
      if (ch < n)
        while (a[ch].first <= t) {
          if (ch == n) break;
          if (a[ch].second < Q.back()) {
            Q.push(a[ch].second * (-1));
          } else {
            q.push(a[ch].second * (-1));
          }
          ch++;
        }
      Q.pop();
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
