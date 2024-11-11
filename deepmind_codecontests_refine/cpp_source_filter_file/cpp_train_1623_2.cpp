#include <bits/stdc++.h>
using namespace std;
long long const inf = 1e9;
long long const mod = 1e9 + 7;
long double const eps = 1e-9;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int c = 0;
  int best = 0;
  int cnt[n];
  for (int i = (0); i < (n); i++) {
    cnt[i] = 0;
    if (i > 0) cnt[i] = cnt[i - 1];
    if (s[i] == 'N')
      c++;
    else {
      best = max(best, c);
      c = 0;
      if (s[i] == 'Y') cnt[i]++;
    }
  }
  best = max(best, c);
  if (best > k) {
    cout << "NO" << endl;
    return 0;
  }
  if (best == k) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = (0); i < (n - k); i++) {
    if (i > 0 && s[i - 1] == 'N') continue;
    if (i + k < n && s[i + k] == 'N') continue;
    int p = 0;
    if (i > 0) p = cnt[i - 1];
    if (cnt[i + k - 1] == p) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
