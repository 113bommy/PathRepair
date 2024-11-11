#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int maxs = 1e5;
int n;
double p[maxn], pp[maxn];
priority_queue<pair<double, int> > pq;
int main() {
  cin >> n;
  double yes = 1;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    pp[i] = p[i] = 1 - p[i] / 100;
    pq.push({(1 - pp[i] * p[i]) / (1 - pp[i]), i});
    yes *= 1 - p[i];
  }
  double res = n;
  for (int i = 0; i < maxs; i++) {
    res += 1 - yes;
    auto cur = pq.top();
    pq.pop();
    yes *= cur.first;
    int idx = cur.second;
    pp[idx] *= p[idx];
    cur.first = (1 - pp[idx] * p[idx]) / (1 - pp[idx]);
    pq.push(cur);
  }
  cout << fixed << setprecision(9) << res << '\n';
  return 0;
}
