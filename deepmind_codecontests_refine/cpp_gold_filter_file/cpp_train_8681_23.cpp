#include <bits/stdc++.h>
using ll = long long;
using namespace std;
constexpr int nax = 100;
int n;
int pt[nax * 2 + 1];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; ++j)
      if (s[j - 1] == '.') pt[i] = j, pt[j + n] = i;
  }
  bool fl[2] = {false, false};
  for (int i = 1; i <= 2 * n; ++i)
    if (not pt[i]) fl[i > n] = true;
  if (fl[0] and fl[1]) return cout << -1 << '\n', 0;
  if (not fl[0])
    for (int i = 1; i <= n; ++i) cout << i << ' ' << pt[i] << '\n';
  else
    for (int i = n + 1; i <= 2 * n; ++i)
      cout << pt[i] << ' ' << (i - n) << '\n';
}
