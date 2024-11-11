#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long int l[200005], r[200005];
long long int lm[200005], rm[200005];
int last[60];
int main() {
  int t, k, i, j, n, m, x, y, q, c, d;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= 30; j++)
      if (!(a[i] & (1 << j)))
        l[i] = max(l[i], (long long int)last[j]);
      else
        last[j] = i;
  }
  for (i = 0; i < 60; i++) last[i] = n + 1;
  for (i = n; i >= 1; i--) {
    r[i] = n + 1;
    for (j = 0; j <= 30; j++)
      if (!(a[i] & (1 << j)))
        r[i] = min(r[i], (long long int)last[j]);
      else
        last[j] = i;
  }
  a[0] = INT_MAX;
  stack<int> s;
  s.push(0);
  for (i = 1; i <= n; i++) {
    while (a[s.top()] <= a[i]) s.pop();
    lm[i] = s.top() + 1;
    s.push(i);
  }
  a[n + 1] = INT_MAX;
  stack<int> s1;
  s1.push(n + 1);
  for (i = n; i >= 1; i--) {
    while (a[s1.top()] < a[i]) s1.pop();
    rm[i] = s1.top() - 1;
    s1.push(i);
  }
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    if (l[i] >= lm[i] && rm[i] >= r[i])
      ans = ans + (l[i] - lm[i] + 1) * (rm[i] - i + 1) +
            (rm[i] - r[i] + 1) * (i - lm[i] + 1) -
            (l[i] - lm[i] + 1) * (rm[i] - r[i] + 1);
    else if (l[i] >= lm[i])
      ans = ans + (l[i] - lm[i] + 1) * (rm[i] - i + 1);
    else if (rm[i] >= r[i])
      ans = ans + (rm[i] - r[i] + 1) * (i - lm[i] + 1);
  }
  cout << ans;
  return 0;
}
