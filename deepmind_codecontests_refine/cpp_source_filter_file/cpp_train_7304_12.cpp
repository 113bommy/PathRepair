#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, k;
  cin >> n >> p >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0ll;
  map<long long, int> freq;
  for (int i = 0; i < n; i++) {
    long long temp = (1ll * a[i] * a[i]) % p;
    temp *= a[i];
    temp %= p;
    temp *= a[i];
    temp %= p;
    temp -= (k * a[i]) % p;
    temp = (temp % p + p) % p;
    ans += freq[temp] + 0ll;
    freq[temp]++;
  }
  cout << ans << endl;
  return 0;
}
