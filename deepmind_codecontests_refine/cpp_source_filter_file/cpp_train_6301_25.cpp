#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
int pref[N];
int n, k;
string s;
bool solve(int x) {
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '1') continue;
    int l = max(i - x - 1, 0), r = min(i + x, n);
    if (pref[r] - pref[l] >= k) return true;
  }
  return false;
}
int main() {
  cin >> n >> k;
  ++k;
  cin >> s;
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + !(s[i - 1] - '0');
  }
  int l = 1, r = n;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (solve(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  if (solve(l))
    cout << l;
  else
    cout << r;
  return 0;
}
