#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  long long a[n], s = 0;
  long long moves = k;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  sort(a, a + n);
  long long amin, amax;
  for (long long i = 0; i < n;) {
    long long j = i;
    while (j < n && a[j] == a[i]) j++;
    long long g = 1e9 + 5;
    if (j < n) g = a[j] - a[i];
    if (g * j <= k) {
      k -= g * j;
    } else {
      amin = a[i] + k / j;
      break;
    }
    i = j;
  }
  if (amin > s / n) amin = s / n;
  reverse(a, a + n);
  for (long long i = 0; i < n;) {
    long long j = i;
    while (j < n && a[j] == a[i]) j++;
    long long g = 1e9 + 5;
    if (j < n) g = a[j] - a[i];
    if (g * j <= moves) {
      moves -= g * j;
    } else {
      amax = a[i] - moves / j;
      break;
    }
    i = j;
  }
  if (amax < (s + n - 1) / n) amax = (s + n - 1) / n;
  cout << amax - amin << endl;
}
