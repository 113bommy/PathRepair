#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, N = 100010;
const long long INFL = 1e18;
int n, p[N], a[N];
int pw(int a, int b) {
  int res = 1;
  for (int i = 0; (1LL << i) <= b; i++) {
    if (b & (1LL << i)) res = (1LL * res * a) % n;
    a = (1LL * a * a) % n;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  if (n == 1) return cout << "YES\n1\n", 0;
  if (n == 4) return cout << "YES\n1\n3\n2\n4\n", 0;
  bool prime = 1;
  if (n == 1) prime = 0;
  if (n == 2) prime = 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      prime = 0;
      break;
    }
  }
  if (!prime) return cout << "NO\n", 0;
  for (int i = 1; i <= n - 1; i++) p[i] = i;
  a[1] = 1, a[n] = n;
  cout << "YES\n";
  for (int i = 2; i <= n - 1; i++) {
    a[i] = (1LL * p[i] * pw(p[i - 1], n - 2)) % n;
  }
  for (int i = 1; i <= n; i++) cout << a[i] << "\n";
}
