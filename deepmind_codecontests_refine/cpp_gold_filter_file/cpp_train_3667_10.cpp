#include <bits/stdc++.h>
using namespace std;
vector<long long int> g[100005];
long long int vis[100005];
vector<double> ans;
int32_t main() {
  long long int t = 1;
  while (t--) {
    long long int n;
    scanf("%lld", &n);
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }
    stack<pair<long long int, long long int> > s;
    pair<long long int, long long int> p, q;
    for (long long int i = n - 1; i >= 0; i--) {
      s.push({1, a[i]});
      while (true) {
        if (s.size() < 2) break;
        p = s.top();
        s.pop();
        q = s.top();
        s.pop();
        if (p.second * q.first < q.second * p.first) {
          s.push(q);
          s.push(p);
          break;
        } else {
          p.second = (p.second + q.second);
          p.first = p.first + q.first;
          s.push(p);
        }
      }
    }
    while (!s.empty()) {
      p = s.top();
      s.pop();
      for (long long int i = 0; i < p.first; i++)
        printf("%.10lf\n", (double)p.second / p.first);
    }
  }
  return 0;
}
