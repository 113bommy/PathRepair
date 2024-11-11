#include <bits/stdc++.h>
using namespace std;
bool isPrime(long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int power(int x, int y, int p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res % p;
}
int cnt[1000007] = {0};
void solve() {
  long long n, i, j, k, l, p, o, a, b, d, q, x, y, min, ans, flag = 0;
  cin >> n >> k;
  std::vector<int> v;
  map<int, int> m;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    flag = 0;
    if (!m[p]) {
      m[p]++;
      v.push_back(p);
      if (v.size() > k) {
        m[v[v.size() - k] - 1] = 0;
      }
    }
  }
  std::vector<int> vec;
  for (j = v.size() - 1, q = 0; j >= 0 && q < k; j--, q++) {
    vec.push_back(v[j]);
  }
  cout << vec.size() << '\n';
  for (int i = 0; i < vec.size(); ++i) {
    cout << vec[i] << " ";
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
