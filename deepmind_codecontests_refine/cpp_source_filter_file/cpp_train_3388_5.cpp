#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, -1, 0, 1};
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    v[i] ^= 1;
  }
  long long l = 0, r = 0, sum = 0, val = 0;
  long long x = 0, y = 0;
  for (r = 0; r < n; r++) {
    sum += v[r];
    while (sum > k) {
      sum -= v[l];
      l++;
    }
    if (r - l + 1 > val) {
      val = r - l + 1;
      x = l, y = r;
    }
  }
  cout << val << "\n";
  for (long long i = 0; i < n; i++) {
    if (i >= x && i <= y)
      cout << (1) << " ";
    else
      cout << 1 - v[i] << " ";
  }
}
