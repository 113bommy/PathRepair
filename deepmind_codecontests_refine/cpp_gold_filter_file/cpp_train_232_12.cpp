#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
long long int MulMod(long long int a, long long int b) { return (a * b) % MOD; }
long long int AddMod(long long int a, long long int b) { return (a + b) % MOD; }
const long long int MAXN = 1e5 + 10;
long long int a[MAXN];
void solving() {
  long long int n;
  cin >> n;
  for (long long int i = (1); i <= (n); i++) cin >> a[i];
  if (n == 1) {
    cout << 1 << " " << 1 << '\n';
    cout << -a[1] << '\n';
    cout << 1 << " " << 1 << '\n';
    cout << 0 << '\n';
    cout << 1 << " " << 1 << '\n';
    cout << 0 << '\n';
  } else {
    cout << 1 << " " << 1 << '\n';
    for (long long int i = (1); i <= (1); i++) cout << a[i] * (n - 1) << " ";
    cout << '\n';
    for (long long int i = (1); i <= (1); i++) a[i] = a[i] + (n - 1) * a[i];
    cout << 2 << " " << n << '\n';
    for (long long int i = (2); i <= (n); i++) cout << a[i] * (n - 1) << " ";
    cout << '\n';
    for (long long int i = (2); i <= (n); i++) a[i] = a[i] + (n - 1) * a[i];
    cout << 1 << " " << n << '\n';
    for (long long int i = (1); i <= (n); i++) cout << -a[i] << " ";
    cout << '\n';
    for (long long int i = (1); i <= (n); i++) assert(a[i] % n == 0);
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  for (long long int i = (1); i <= (t); i++) {
    solving();
  }
}
