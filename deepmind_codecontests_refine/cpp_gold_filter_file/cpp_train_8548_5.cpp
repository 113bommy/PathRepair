#include <bits/stdc++.h>
using namespace std;
long long n, k, res, b, mid;
string s, t;
void solve() {
  cin >> n >> k;
  cin >> s >> t;
  if (k == 1) {
    cout << n << "\n";
    return;
  }
  res = 0;
  b = n;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      b = i;
      break;
    }
    res++;
  }
  mid = 0;
  for (int i = b; i < n; i++) {
    if (mid + 2 >= k) {
      res += k * (n - i);
      break;
    }
    res += mid + 2;
    if (i + 1 < n) {
      mid *= 2;
      if (s[i + 1] == 'a') mid++;
      if (t[i + 1] == 'b') mid++;
    }
  }
  cout << res << "\n";
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
