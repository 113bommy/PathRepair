#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "{" << p.first << "," << p.second << "}";
  return os;
}
const int N = 3e5 + 5;
const int oo = 1e9 + 7;
bool isp(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
int inv[N];
void for_all_mod_inverse(long long m) {
  inv[1] = 1;
  for (int i = 2; i < m; ++i) inv[i] = (m - (m / i) * inv[m % i] % m) % m;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n == 1)
    cout << "YES\n1\n";
  else if (n == 4)
    cout << "YES\n1 3 2 4\n";
  else if (isp(n)) {
    cout << "YES\n";
    for_all_mod_inverse(n);
    cout << 1 << "\n";
    for (int i = 2; i < n; i++)
      cout << ((i) * (inv[i - 1]) % n + n) % n << "\n";
    cout << n << "\n";
  } else
    cout << "NO\n";
}
