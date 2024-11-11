#include <bits/stdc++.h>
using namespace std;
int x[10002], y[10002];
bool used[10002];
int f;
int s[10002];
int n, m, k;
const long long mx = 1000000009;
int main() {
  cin >> n >> m >> k;
  bool good = 0;
  s[0] = mx;
  int beg;
  for (int i = 1; i <= k; ++i) {
    scanf("%d%d", &y[i], &x[i]);
    if (x[i] == n && y[i] == m) {
      good = 1;
      beg = i;
    }
    if (x[i] == 1 && y[i] == 1) f = i;
    s[i] = mx;
  }
  if (!good) {
    k++;
    x[k] = n + 1;
    y[k] = m + 1;
    beg = k;
  }
  s[beg] = 0;
  while (1) {
    int t = 0;
    for (int i = 1; i <= k; ++i)
      if (!used[i] && s[i] < s[t]) t = i;
    if (t == f || !t) break;
    used[t] = 1;
    for (int i = 1; i <= k; ++i) {
      if (abs(x[i] - x[t]) + abs(y[t] - y[i]) <= 1)
        s[i] = min(s[t], s[i]);
      else if (abs(x[i] - x[t]) <= 2 || abs(y[i] - y[t]) <= 2)
        s[i] = min(s[t] + 1, s[i]);
    }
  }
  if (s[f] == mx)
    cout << -1;
  else
    cout << s[f];
  return 0;
}
