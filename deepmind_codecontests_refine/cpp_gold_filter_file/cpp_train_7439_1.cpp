#include <bits/stdc++.h>
using namespace std;
long long v[1000009];
long long d[1000009];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  long long lastm(-1), lastv(-1);
  for (long long i = 0; i < n; ++i) {
    if (i >= 2 && v[i - 1] >= v[i] && v[i - 2] < v[i - 1]) {
      lastm = i - 1;
    }
    if (i >= 2 && v[i - 1] <= v[i] && v[i - 2] > v[i - 1]) {
      lastv = i - 1;
    }
    if (lastm != -1 && v[i - 1] >= v[i]) {
      d[i] =
          max(d[lastm] + v[lastm + 1] - v[i], d[lastm - 1] + v[lastm] - v[i]);
    } else if (lastv != -1) {
      d[i] =
          max(d[lastv] + v[i] - v[lastv + 1], d[lastv - 1] + v[i] - v[lastv]);
    } else {
      d[i] = max(v[i] - v[0], v[0] - v[i]);
    }
  }
  cout << d[n - 1];
  return 0;
}
