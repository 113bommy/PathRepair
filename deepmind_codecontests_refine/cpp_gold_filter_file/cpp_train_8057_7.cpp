#include <bits/stdc++.h>
using namespace std;
const long long MAXON = 1e5;
long long h[MAXON];
long long p[MAXON];
long long n, m;
bool check(long long t) {
  long long r = 0;
  long long l = 0;
  while (l < n && r < m) {
    if (p[r] >= h[l]) {
      while (r < m && p[r] - h[l] <= t) {
        r++;
      }
    } else {
      if (h[l] - p[r] > t) {
        return false;
      }
      long long pos = max((t - (h[l] - p[r])) / 2, t - 2 * (h[l] - p[r]));
      pos += h[l];
      while (r < m && p[r] <= pos) {
        r++;
      }
    }
    l++;
  }
  if (r < m) {
    return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> p[i];
  }
  long long l = -1;
  long long r = 20000000001ll;
  while (l + 1 < r) {
    long long m = (l + r) / 2ll;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r;
}
