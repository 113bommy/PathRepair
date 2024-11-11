#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10, MAX = 2e5 + 1e4, MOD = 1e9 + 7, MAXL = 25;
void OUT(long double o, int x) {
  cout << fixed << setprecision(x) << o;
  return;
}
long long a[MAX];
long long f(long long n, long long x) {
  if (x % 2 == 1) return (x / 2) + 1;
  if (n % 2 == 0) return ((n + 1) / 2) + f(n / 2, x / 2);
  if (x == 2) return ((n + 1) / 2) + f(n / 2, x / 2);
  return ((n + 1) / 2) + f(n / 2, x / 2 - 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, q;
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    long long x;
    cin >> x;
    cout << f(n, x) << "\n";
  }
  return 0;
}
