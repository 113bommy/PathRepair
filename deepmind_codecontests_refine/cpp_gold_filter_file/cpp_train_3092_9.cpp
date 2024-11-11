#include <bits/stdc++.h>
using namespace std;
void cal_primearray(long long n) {
  vector<long long> prime(5000005, 1);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == 1) {
      for (int i = p * 2; i <= n; i += p) prime[i] = 0;
    }
  }
}
long long modexpo(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long expo(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6) {
    if ((n % i == 0) || (n % (i + 2) == 0)) return false;
  }
  return true;
}
long long max_value(vector<long long> arr) {
  long long m = 0;
  for (int i = 0; i < arr.size(); i++) m = max(m, arr[i]);
  return m;
}
long double dist(long double x1, long double y1, long double z1, long double x2,
                 long double y2, long double z2) {
  return (long double)sqrt((long double)((x1 - x2) * (x1 - x2) +
                                         (y1 - y2) * (y1 - y2) +
                                         (z1 - z2) * (z1 - z2)));
}
long long nCr(long long n, long long r) {
  if (r == 0) return 1;
  return (((n)*nCr(n - 1, r - 1)) / (r));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a, b;
  cin >> n >> a >> b;
  int arr[n + 1][n + 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) arr[i][j] = 0;
  if (n == 1) {
    cout << "YES\n";
    cout << 0 << endl;
    return 0;
  }
  if (a == 1 || b == 1) {
    if (a == 1 && b == 1) {
      if (n == 2 || n == 3) {
        cout << "NO\n";
        return 0;
      }
      for (int i = 1; i < n; i++) arr[i][i + 1] = 1;
    } else if (a == 1) {
      for (int i = 1; i <= b - 1; i++)
        for (int j = i + 1; j <= n; j++) arr[i][j] = 1;
    } else {
      for (int i = a; i <= n; i++)
        for (int j = i + 1; j <= n; j++) arr[i][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (arr[i][j] == 1 || arr[j][i] == 1)
          arr[j][i] = arr[i][j] = 1;
        else
          arr[i][j] = arr[j][i] = 0;
      }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) cout << arr[i][j];
      cout << "\n";
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}
