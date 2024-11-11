#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q, l, r;
  scanf("%d %d", &n, &q);
  int a[n + 2], d[n + 1];
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) d[i - 1] = abs(a[i] - a[i - 1]);
  int pmx[n + 1], nmx[n + 1];
  stack<int> s;
  s.push(1);
  pmx[1] = 0;
  nmx[n - 1] = n + 1;
  for (int i = 2; i < n; i++) {
    if (d[i] <= d[s.top()]) {
      pmx[i] = s.top();
      s.push(i);
    } else {
      while (!s.empty() && d[i] > d[s.top()]) s.pop();
      if (!s.empty())
        pmx[i] = s.top();
      else
        pmx[i] = 0;
      s.push(i);
    }
  }
  while (!s.empty()) s.pop();
  s.push(n - 1);
  for (int i = n - 2; i >= 1; i--) {
    if (d[i] <= d[s.top()]) {
      nmx[i] = s.top();
      s.push(i);
    } else {
      while (!s.empty() && d[i] >= d[s.top()]) s.pop();
      if (!s.empty())
        nmx[i] = s.top();
      else
        nmx[i] = n + 1;
      s.push(i);
    }
  }
  while (q--) {
    scanf("%d %d", &l, &r);
    r--;
    long long int ans = 0;
    for (int i = l; i <= r; i++) {
      int pv, nx;
      pv = max(pmx[i] + 1, l);
      nx = min(nmx[i] - 1, r);
      ans += (long long int)d[i] *
             ((long long int)(i - pv) * (nx - i) + (i - pv + 1) + (nx - i));
    }
    cout << ans << endl;
  }
}
