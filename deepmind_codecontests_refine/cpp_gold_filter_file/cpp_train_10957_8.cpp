#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  char c;
  long long a[n], b[n];
  for (long long i = 0; i < n; i++) {
    cin >> c;
    a[i] = c - '0';
  }
  for (long long i = 0; i < n; i++) {
    cin >> c;
    b[i] = c - '0';
  }
  long long f = 0, l = n - 1, sf = 0, sl = 0;
  long long k = 0;
  long long p[n * 2];
  for (long long i = 0; i < n - 1; i++) {
    if (((a[l] + sl) % 2) == b[n - 1 - i]) {
      if ((sl % 2) == 1) {
        l++;
      } else {
        l--;
      }
      continue;
    } else if ((a[l] + sl) % 2 != (a[f] + sl) % 2) {
      p[k++] = 1;
      sf++;
    }
    if ((a[l] + sl) % 2 != b[n - 1 - i]) {
      p[k++] = abs(l - f) + 1;
      long long tmp = l;
      if (sl % 2 == 0) {
        l = f + 1;
        f = tmp;
      } else {
        l = f - 1;
        f = tmp;
      }
      sl++;
      sf = 0;
    }
  }
  if ((a[l] + sl) % 2 != b[0]) {
    p[k++] = 1;
  }
  cout << k;
  for (long long i = 0; i < k; i++) {
    cout << ' ' << p[i];
  }
  cout << endl;
  return;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
