#include <bits/stdc++.h>
using namespace std;
long long int h[1000005];
long long int pp[1000005];
long long int gethash(long long int i, long long int j) {
  return (h[j + 1] - h[i] + 1000000009) % 1000000009;
}
bool check(long long int k, long long int n) {
  cout << k << "\n";
  long long int h1, h2, h3;
  h1 = gethash(0, k - 1);
  h2 = gethash(n - k, n - 1);
  h1 = (h1 * pp[n - k]) % 1000000009;
  h2 = (h2 * pp[0]) % 1000000009;
  cout << h1 << " " << h2 << "\n";
  if (h1 != h2) return false;
  for (long long int i = k; i < n - 1; i++) {
    h3 = gethash(i - k + 1, i);
    h3 = (h3 * pp[0]) % 1000000009;
    cout << h3 << "\n";
    if (h3 == h1) return true;
  }
  return false;
}
void solve() {
  string s;
  cin >> s;
  long long int n = s.length(), ans = 0;
  vector<long long int> z(n, 0);
  for (long long int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (z[i] + i - 1 > r) l = i, r = z[i] + i - 1;
  }
  long long int ma = 0, id = -1;
  for (long long int i = 1; i < n - 1; i++) {
    if (ma < z[i]) {
      ma = z[i];
      id = i;
    }
  }
  for (long long int i = n - 1; i >= 0; i--) {
    if (i + z[i] == n) {
      if (ma > z[i])
        ans = max(ans, z[i]);
      else if (ma == z[i] && id + ma != n)
        ans = max(ans, z[i]);
    }
  }
  if (ans == 0)
    cout << "Just a Legend";
  else
    cout << s.substr(0, ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
