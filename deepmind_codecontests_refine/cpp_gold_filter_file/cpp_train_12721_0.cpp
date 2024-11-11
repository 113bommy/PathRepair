#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = 1e16;
const long long MAX_N = 100010;
int main() {
  long long q;
  cin >> q;
  vector<long long> e(9);
  e[0] = 1;
  for (long long i = 1; i <= 8; i++) {
    e[i] = 3 * e[i - 1];
  }
  vector<long long> v;
  for (long long b = 0; b < 1 << 9; b++) {
    if (b == 0) {
      continue;
    }
    long long x = 0;
    for (long long i = 0; i < 9; i++) {
      if (b & 1 << i) {
        x += e[i];
      }
    }
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  for (long long loop = 0; loop < q; loop++) {
    long long n;
    cin >> n;
    if (9841 < n) {
      cout << 19683 << endl;
      continue;
    }
    for (auto p : v) {
      if (n <= p) {
        cout << p << endl;
        break;
      }
    }
  }
  return 0;
}
