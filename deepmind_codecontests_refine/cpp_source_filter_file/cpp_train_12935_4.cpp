#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 9;
const int MaxM = 100005;
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) cout << p << " ";
}
void solve() {
  int n;
  cin >> n;
  long long ans = 0;
  int c = 0;
  int j = 0;
  vector<int> v(21, 0);
  for (int i = 0; i < n; i++) {
    cin >> c;
    j = 0;
    while (c > 0) {
      if (c & 1) {
        v[j]++;
      }
      j++;
      c = c >> 1;
    }
  }
  while (n--) {
    c = 0;
    for (int i = 0; i < 21; i++) {
      if (v[i] != 0) {
        c += 1 << i;
        v[i]--;
      }
    }
    ans += c * c;
  }
  cout << ans;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
