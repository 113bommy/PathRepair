#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long k, n, s, p;
  cin >> k >> n >> s >> p;
  long long l = 0, r = 1e9;
  while (r - l > 1) {
    long long m = (r + l) / 2;
    if (((m * p) / k) * s >= n) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r;
}
