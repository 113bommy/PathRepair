#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const int inf = 1e9 + 5;
int n;
int pref[maxn];
int sieve[(int)1e6 + 5];
void Sieve() {
  for (int i = 2; i * i <= (int)1e6; i++) {
    if (sieve[i]) continue;
    for (int j = i * i; j <= (int)1e6; j += i) sieve[j] = 1;
  }
  for (int i = 1; i <= (int)1e6; i++) pref[i] = pref[i - 1] + !sieve[i];
}
void Solve() {
  cin >> n;
  int m = sqrt(n);
  cout << pref[n] - pref[m] + 1 << '/n';
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  Sieve();
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
