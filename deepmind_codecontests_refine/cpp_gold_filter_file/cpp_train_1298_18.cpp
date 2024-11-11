#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k, p;
  cin >> n >> m >> k >> p;
  vector<int> a(n), h(n);
  for (int i = 0; i < (int)n; ++i) cin >> h[i] >> a[i];
  long long int up = (m + 2) * 1000000000;
  long long int low = 0;
  for (int i = 0; i < (int)n; ++i) low = max(low, (long long int)a[i]);
  while (low < up) {
    long long int X = (up + low) / 2;
    long long int hits_needed = 0;
    for (int i = 0; i < (int)n; ++i) {
      hits_needed += max(0ll, (h[i] + a[i] * m - X + p - 1) / p);
    }
    int ok = 1;
    if (hits_needed > m * k) {
      ok = 0;
    } else {
      vector<long long int> v;
      for (int i = 0; i < (int)n; ++i) {
        long long int y = h[i] + a[i] * m - X;
        long long int h0 = h[i];
        long long int t0 = 0;
        while (y > 0) {
          long long int res = y % p;
          if (res == 0) res = p;
          long long int t1_adv = max(0ll, (res - h0 + a[i] - 1) / a[i]);
          t0 += t1_adv;
          v.push_back(t0);
          h0 += a[i] * t1_adv;
          long long int delta = min<long long int>(h0, p);
          h0 -= delta;
          y -= delta;
        }
      }
      sort(v.begin(), v.end());
      int ptr = 0;
      for (int day = 0; day < m; ++day) {
        for (int i = 0; i < (int)k; ++i) {
          if (ptr < (int)v.size() && v[ptr] <= day) {
            ++ptr;
          } else {
            break;
          }
        }
      }
      ok = (ptr == (int)v.size());
    }
    if (ok) {
      up = X;
    } else {
      low = X + 1;
    }
  }
  cout << up << endl;
}
