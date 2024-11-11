#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int> > s;
int ans, n, p[200005], l[200005], r[200005], st[200005];
int main() {
  ios::sync_with_stdio(false);
  int i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> p[i];
    st[p[i]] = i;
    r[i] = n + 1;
  }
  for (i = 1; i <= n; i++) {
    while (!s.empty() && s.top().first < p[i]) s.pop();
    if (!s.empty()) l[p[i]] = s.top().second;
    s.push(make_pair(p[i], i));
  }
  while (!s.empty()) s.pop();
  for (i = n; i; i--) {
    while (!s.empty() && s.top().first < p[i]) s.pop();
    if (!s.empty()) r[p[i]] = s.top().second;
    s.push(make_pair(p[i], i));
  }
  for (i = 1; i <= n; i++) {
    if (r[i] - st[i] < st[i] - l[i])
      for (j = st[i] + 1; j < r[i]; j++)
        ans += l[i] < st[i - p[j]] && st[i - p[j]] < r[i];
    else
      for (j = l[i] + 1; j < st[i]; j++)
        ans += l[i] < st[i - p[j]] && st[i - p[j]] < r[i];
  }
  cout << ans;
  return 0;
}
