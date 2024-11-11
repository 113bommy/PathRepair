#include <bits/stdc++.h>
using namespace std;
int n;
long long x, m, res;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x >> m;
    if (x & 1) {
      res ^= x;
      --x;
      ++m;
    }
    if (m & 1) {
      res ^= x + m - 1;
      --m;
    }
    if ((m / 2) % 2) {
      res ^= 1;
    }
  }
  if (res) {
    cout << "tolik";
  } else {
    cout << "bolik";
  }
  cout << '\n';
  return 0;
}
