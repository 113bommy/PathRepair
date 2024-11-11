#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[1000005];
long long a[1000005], b[1000005];
deque<pair<int, int> > dq;
int main() {
  scanf("%d%d", &n, &m);
  while (n--) {
    while (!dq.empty()) dq.pop_front();
    int l;
    scanf("%d", &l);
    for (int i = 1; i <= l; ++i) scanf("%d", &x[i]);
    for (int i = 1; i <= l; ++i) {
      int r = i + (m - l);
      while (!dq.empty() && dq.back().first <= x[i]) dq.pop_back();
      dq.push_back({x[i], r});
      if (dq.front().first < 0 && i <= m - l)
        a[i] += 0;
      else
        a[i] += dq.front().first;
      if (dq.front().second == i) dq.pop_front();
    }
    int last = l;
    while (!dq.empty() && dq.front().first > 0) {
      b[last + 1] += dq.front().first;
      b[dq.front().second + 1] -= dq.front().first;
      last = dq.front().second + 1;
      dq.pop_front();
    }
  }
  for (int i = 1; i <= m; ++i) {
    b[i] += b[i - 1];
    a[i] += b[i];
  }
  for (int i = 1; i <= m; ++i) printf("%lld ", a[i]);
  return 0;
}
