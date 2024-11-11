#include <bits/stdc++.h>
using namespace std;
long long candles(int n, int m, int left = 0) {
  if (n + left < m) {
    return n + left;
  } else if (n + left == m) {
    return n + left + 1;
  } else {
    return candles((n + left) / m, m, (n + left) % m);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  int _min = n;
  for (int i = n; i >= n / 2 + 1; i -= 1) {
    if (i % m == 0 && i < _min) {
      _min = i;
    }
  }
  if (_min % m == 0) {
    cout << _min;
  } else {
    cout << -1;
  }
}
