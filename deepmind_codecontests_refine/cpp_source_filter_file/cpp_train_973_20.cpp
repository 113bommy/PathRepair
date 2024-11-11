#include <bits/stdc++.h>
using namespace std;
int gcd(int m, int n) {
  if (n == 0) return m;
  return gcd(n, m % n);
}
long long binpow(int a, int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 1)
    return binpow(a, n - 1) * a;
  return binpow(a, n / 2) * binpow(a, n / 2);
}
vector<char> eratosphen(long long n) {
  vector<char> prime(n + 1, true);
  prime[0] = false;
  prime[1] = false;
  for (long long i = 2; i * i <= n; i++)
    if (prime[i])
      if (i * 1ll * i <= n)
        for (long long j = i * i; j <= n; j += i) prime[j] = false;
  return prime;
}
int g(int n) { return n ^ (n >> 1); }
double c(int n, int m) {
  int B[500][500];
  for (int i = 0; i <= n; ++i) {
    B[i][0] = 1;
    B[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
    }
  }
  return B[n][m];
}
const int inf = 100000005;
const int nax = 5005;
int degree[nax];
bool t[nax][nax];
int main() {
  ifstream f("INPUT.TXT");
  ofstream o("OUTPUT.TXT");
  int n = 0;
  long long r = 0;
  long long a[100][100];
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    r = 0;
    for (int j = 0; j < n; j++)
      if (a[i][j] != -1) r ^= a[i][j];
    cout << r << " ";
  }
  return 0;
}
