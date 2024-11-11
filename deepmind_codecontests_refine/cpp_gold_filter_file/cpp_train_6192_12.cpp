#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<long long, long> > q;
unordered_map<long long, long> m;
int n;
long long leng[301];
long cost[301];
long gcd(long long a, long long b) {
  long long x;
  while (a != b && a != 0 && b != 0) {
    x = a % b;
    a = b;
    b = x;
  }
  return max(a, b);
}
int main() {
  long gt;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> leng[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }
  q.push(make_pair(0, 0));
  m[0] = 0;
  while (!q.empty()) {
    pair<long long, long> pa = q.top();
    q.pop();
    if (pa.first != m[pa.second]) continue;
    if (pa.second == 1) {
      cout << -pa.first;
      return 0;
    }
    for (int i = 1; i <= n; i++) {
      gt = gcd(pa.second, leng[i]);
      if (m.find(gt) == m.end() || m[gt] < pa.first - cost[i]) {
        m[gt] = pa.first - cost[i];
        q.push(make_pair(pa.first - cost[i], gt));
      }
    }
  }
  cout << -1;
  return 0;
}
