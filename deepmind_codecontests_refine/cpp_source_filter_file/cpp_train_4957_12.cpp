#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 100;
const int mod = (int)1e9 + 7;
int n, T, t[maxn], ans;
int first(int cur) {
  int res = 0;
  for (int i = (1); i <= (n); ++i) {
    cur++;
    if (cur >= T) break;
    if (cur >= t[i]) res++;
  }
  return res;
}
int main() {
  cin >> n >> T;
  for (int i = (1); i <= (n); ++i) cin >> t[i];
  int l = 0, r = T;
  while (r - l > 5) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    if (first(m1) < first(m2))
      l = m1;
    else
      r = m2;
  }
  for (int i = (l); i <= (r); ++i) ans = max(ans, first(i));
  cout << ans;
}
