#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
long long cnk(long long n, long long k, vector<long long>& fac) {
  if (n < k) {
    return 0;
  }
  return (fac[n] / fac[k]) / fac[n - k];
}
int main() {
  vector<long long> fac(21);
  fac[0] = 1;
  for (auto i = 1; i <= 20; ++i) {
    fac[i] = fac[i - 1] * i;
  }
  int t;
  cin >> t;
  for (auto test = 0; test < t; ++test) {
    int key;
    cin >> key;
    map<int, int> r;
    int div = 2;
    int count = 0;
    while (key > 0) {
      ++count;
      ++r[-(key % div)];
      key /= div;
      ++div;
    }
    long long ans = 1;
    int placed = 0;
    for (auto it = r.begin(); it != r.end(); ++it) {
      ans *= cnk(count - max(-it->first - 1, 0) - placed, it->second, fac);
      placed += it->second;
    }
    long long inv = 0;
    if (r[0] != 0) {
      --r[0];
      inv = 1;
      count -= 1;
      placed = 0;
      for (auto it = r.begin(); it != r.end(); ++it) {
        inv *= cnk(count - max(-it->first - 1, 0) - placed, it->second, fac);
        placed += it->second;
      }
    }
    cout << ans - inv - 1 << '\n';
  }
  return 0;
}
