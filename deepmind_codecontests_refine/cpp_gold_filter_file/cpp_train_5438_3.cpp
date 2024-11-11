#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  auto f = [](int &x) {
    while (x >= 26) x -= 26;
  };
  if (s.length() <= 2) {
    cout << "YES" << '\n';
  } else {
    for (int i = 2; i < (int)s.length(); i++) {
      int x = s[i - 2] - 'A' + s[i - 1] - 'A';
      f(x);
      if (x != s[i] - 'A') {
        cout << "NO" << '\n';
        return 0;
      }
    }
    cout << "YES" << '\n';
  }
  return 0;
}
