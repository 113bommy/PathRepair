#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[1000005], b[1000005];
long long l[1000005], r[1000005];
long long ff[1000005];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  long long maxx = -1e9, maxp;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > maxx) {
      maxx = a[i];
      maxp = i;
    }
  }
  for (long long i = 0; i < n; i++) {
    b[i] = a[(i + maxp) % n];
  }
  b[n] = a[maxp];
  r[n] = n;
  l[0] = 0;
  for (long long i = n - 1; i >= 1; i--) {
    r[i] = i + 1;
    while (r[i] < n && b[i] > b[r[i]]) {
      r[i] = r[r[i]];
    }
    if (r[i] < n && b[i] == b[r[i]]) {
      ff[i] = ff[r[i]] + 1;
      r[i] = r[r[i]];
    }
  }
  for (long long i = 1; i < n; i++) {
    l[i] = i - 1;
    while (l[i] && b[i] >= b[l[i]]) {
      l[i] = l[l[i]];
    }
  }
  long long ans = 0;
  for (long long i = 1; i < n; i++) {
    ans += ff[i];
    if (l[i] != 0 || r[i] != n) {
      ans += 2;
    } else {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
