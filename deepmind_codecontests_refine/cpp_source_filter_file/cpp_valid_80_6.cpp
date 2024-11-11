#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int p = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '0') {
      p = i + 1;
      break;
    }
  if (!p)
    cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n;
  else if (p <= n / 2)
    cout << p << ' ' << n << ' ' << p + 1 << ' ' << n;
  else
    cout << 1 << ' ' << p - 1 << ' ' << 1 << ' ' << p;
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
