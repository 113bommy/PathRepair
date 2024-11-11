#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l, r, d;
  cin >> n >> l >> r >> d;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int x = 0;
  sort(v.begin(), v.end());
  for (int i = 2; i < (1 << n); i++) {
    long long sum = 0;
    long long m = 0;
    long long b = LLONG_MAX;
    bitset<64> bit(i);
    for (int j = 0; j <= n; j++) {
      if (bit[j]) {
        sum += v[j];
        if (v[j] >= m) {
          m = v[j];
        }
        if (v[j] <= b) {
          b = v[j];
        }
      }
    }
    int y = m - b;
    if (bit.count() > 1) {
      if (sum >= l && sum <= r && y >= d) {
        x++;
      }
    }
  }
  cout << x;
}
