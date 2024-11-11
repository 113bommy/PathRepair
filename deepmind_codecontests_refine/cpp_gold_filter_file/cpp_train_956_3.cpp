#include <bits/stdc++.h>
using namespace std;
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long int binomialCoeff(long long int n, long long int k) {
  long long int res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
bool prime[100005];
void Sieve(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
const int Nmax = 1e6 + 5;
long long int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, d;
  cin >> n >> m >> d;
  int c[m];
  for (int i = 0; i < m; i++) cin >> c[i];
  bool yes = true;
  int last = 0;
  for (int i = 0; i < m; i++) {
    last += d + c[i] - 1;
  }
  if (last + d < n + 1) {
    cout << "NO";
    return 0;
  } else
    cout << "YES\n";
  int sum = 0;
  for (int i = 0; i < m; i++) {
    sum += c[i];
  }
  vector<int> ans(n, 0);
  int space = n - sum;
  int j = 0;
  for (int i = 0; i < m; i++) {
    if (space - d + 1 >= 0) {
      for (int k = j + d - 1; k <= j + d + c[i] - 2; k++) ans[k] = i + 1;
      space = space - d + 1;
      j += d + c[i] - 1;
    } else {
      for (int k = j; k <= j + c[i] - 1; k++) ans[k] = i + 1;
      j += c[i];
    }
  }
  for (auto x : ans) cout << x << " ";
}
