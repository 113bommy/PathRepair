#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, r, res = 1;
  cin >> n;
  map<long long, long long> m;
  map<long long, long long> b;
  vector<long long> a(n);
  for (i = 0; i < n; ++i) {
    cin >> a[i];
    ++m[a[i]];
  }
  for (i = 0; i < n; ++i) {
    cin >> j;
    if (j == a[i]) {
      b[j] += 1;
    }
    ++m[j];
  }
  cin >> r;
  for (map<long long, long long>::iterator it = m.begin(); it != m.end();
       ++it) {
    for (i = it->second; i >= 2; --i) {
      if (b[it->first] > 0 && i % 2 == 0) {
        res *= (i / 2);
        --b[it->first];
      } else {
        res *= i;
      }
      res %= r;
    }
  }
  cout << res;
  return 0;
}
