#include <bits/stdc++.h>
using namespace std;
long long n, sk;
long long ans;
long long ans1;
int a[10100];
int t[10100];
int pref[10100];
int main() {
  cin >> n >> sk;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long j = 1; j <= n; j++) {
    cin >> t[j];
    if (t[j] == 1) ans1 += a[j];
  }
  int sum = 0;
  for (long long i = 1; i <= n; i++) {
    if (t[i] == 0) {
      pref[i] = a[i] + pref[i - 1];
    } else
      pref[i] = pref[i - 1];
  }
  for (long long j = 1; j <= n - sk + 1; j++) {
    sum = max(sum, pref[j + sk - 1] - pref[j - 1]);
  }
  cout << sum + ans1;
}
