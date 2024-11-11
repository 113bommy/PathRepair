#include <bits/stdc++.h>
using namespace std;
int m[2000] = {0};
void solve() {
  int k, a, b;
  cin >> k >> a >> b;
  string s;
  cin >> s;
  if (k * a > s.size() || k * b < s.size()) {
    cout << "No solution\n";
    return;
  }
  int n = s.size(), len = n / k, temp = n % len, i = 0;
  while (temp) {
    cout << s[i];
    ++i;
    if (i % (len + 1) == 0 && i != 0) {
      cout << "\n";
      --temp;
    }
  }
  for (int j = 0; i + j < n; ++j) {
    if (j % len == 0 && j != 0) cout << '\n';
    cout << s[i + j];
  }
  return;
}
int main() {
  int t = 1;
  while (t--) solve();
}
