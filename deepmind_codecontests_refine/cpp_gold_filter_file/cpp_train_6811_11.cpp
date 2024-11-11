#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int a[maxn];
int n;
int k[maxn];
vector<int> tedad;
const int mod = (1e9 + 7);
void f(int x) {
  int X = x;
  for (int i = 2; i * i <= X; i++) {
    while (x % i == 0) {
      x = x / i;
      tedad.push_back(i);
    }
  }
  if (x > 1) tedad.push_back(x);
  return;
}
long long int F(long long x) {
  long long Q = 1;
  for (int i = 1; i <= x; i++) {
    Q = (Q * i) % mod;
  }
  return Q;
}
long long int T(int x, int p) {
  if (p == 0) {
    return 1;
  }
  long long a = T(x, p / 2);
  if (p % 2 == 0)
    return a * a % mod;
  else
    return (a * a % mod) * x % mod;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f(a[i]);
  }
  sort(tedad.begin(), tedad.end());
  int l, r;
  l = 0;
  r = 1;
  long long ans = 1;
  while (l < tedad.size()) {
    if (r < tedad.size() && tedad[l] == tedad[r]) {
      r++;
    } else {
      ans = ans * T(F(r - l), mod - 2) % mod;
      ans = ans * T(F(n - 1), mod - 2) % mod;
      ans = ans * F(r - l + n - 1) % mod;
      l = r;
      r = l + 1;
    }
  }
  cout << ans % mod << endl;
  return 0;
}
