#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
const int N = 1e5 + 5;
int n, m, k, p, a[N];
long long cur[N], add[N];
bool f(long long x) {
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      Q;
  for (int i = 1; i <= n; i++) {
    cur[i] = x;
    if (x - m * add[i] >= 0) continue;
    Q.push(make_pair(x / add[i], i));
  }
  long long cnt = 0;
  while (!Q.empty() and cnt < m * k) {
    long long day = Q.top().first;
    int i = Q.top().second;
    Q.pop();
    if (day < cnt / k) return 0;
    cur[i] += p;
    cnt++;
    if (cur[i] - m * add[i] >= 0) continue;
    Q.push(make_pair(cur[i] / add[i], i));
  }
  for (int i = 1; i <= n; i++)
    if (cur[i] - add[i] * m <= a[i])
      cnt += (a[i] - (cur[i] - add[i] * m) + p - 1) / p;
  return cnt <= m * k;
}
int main() {
  ios ::sync_with_stdio(0);
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; i++) cin >> a[i] >> add[i];
  long long l = 0, r = 1e15;
  while (l < r) {
    long long m = l + r >> 1;
    if (f(m))
      r = m;
    else
      l = m + 1;
  }
  cout << l << '\n';
  return 0;
}
