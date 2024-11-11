#include <bits/stdc++.h>
using namespace std;
int w[1001], cnt1, cnt2;
int main() {
  int n, s, t, i;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> w[i];
  cin >> s >> t;
  if (s <= t) {
    for (i = s; i < t; i++) cnt1 += w[i];
    for (i = s - 1; i >= 1; i--) cnt2 += w[i];
    for (i = n; i >= t; i--) cnt2 += w[i];
  } else {
    for (i = s - 1; i >= t; i--) cnt1 += w[i];
    for (i = s; i <= n; i++) cnt2 += w[i];
    for (i = 1; i < t; i++) cnt2 += w[i];
  }
  cout << min(cnt1, cnt2);
}
