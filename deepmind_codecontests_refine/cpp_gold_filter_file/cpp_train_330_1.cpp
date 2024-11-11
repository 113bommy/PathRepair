#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long Q_MOD = 998244353;
void go() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout << setprecision(6);
}
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  if (n / 2 < 5) {
    cout << "0 0 0\n";
    return;
  }
  long long a, b, c;
  long long k = 0;
  while (k < n / 2 and arr[0] == arr[k]) k++;
  a = k;
  long long i = k;
  while (i < n / 2 and (i - k) <= a) i++;
  if (i >= n / 2) {
    cout << "0 0 0\n";
    return;
  }
  long long temp = i - 1;
  while (i < n / 2 and arr[i] == arr[temp]) i++;
  b = i - k;
  k = i;
  while (k < n and arr[i] == arr[k]) k++;
  if (k > n / 2) {
    cout << "0 0 0\n";
    return;
  }
  c = k - i;
  for (long long m = k; m < n / 2; m++) {
    long long sm = m + 1;
    while (sm < n and arr[sm] == arr[m]) sm++;
    if (sm <= n / 2) {
      c += (sm - m);
      m = sm - 1;
    } else {
      break;
    }
  }
  if (c <= a)
    cout << "0 0 0\n";
  else
    cout << a << " " << b << " " << c << '\n';
}
signed main() {
  go();
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
