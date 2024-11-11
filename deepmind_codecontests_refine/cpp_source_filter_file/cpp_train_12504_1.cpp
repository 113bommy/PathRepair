#include <bits/stdc++.h>
using namespace std;
const int AX = 2e5 + 66;
int a[AX];
int main() {
  int n;
  long long k;
  cin >> n >> k;
  int x;
  priority_queue<int> q;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (!a[x]) q.push(x);
    a[x]++;
  }
  int res = 0;
  long long tmp = k;
  if (q.size() == 1) {
    cout << res << endl;
    return 0;
  } else
    res = 1;
  while (q.size() > 1) {
    int u = q.top();
    if (tmp < a[u]) {
      tmp = k;
      res++;
      continue;
    }
    q.pop();
    int v = q.top();
    q.pop();
    long long t = (u - v) * a[u];
    if (tmp >= t) {
      tmp -= t;
      a[v] += a[u];
      a[u] = 0;
    } else {
      int delta = tmp / a[u];
      a[u - delta] += a[u];
      tmp -= delta * a[u];
      q.push(u - delta);
      a[u] = 0;
    }
    q.push(v);
  }
  cout << res << endl;
  return 0;
}
