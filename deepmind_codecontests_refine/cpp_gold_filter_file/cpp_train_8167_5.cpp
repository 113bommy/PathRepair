#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
const double PI = acos(-1);
const long long MOD = 1000000007;
long long dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
long long dy[] = {0, +1, 0, -1, +1, -1, +1, -1};
long long powmod(long long a, long long b) {
  long long p = MOD;
  a %= p;
  if (!a) return 0;
  long long pr = 1;
  while (b > 0) {
    if (b & 1) {
      pr *= a;
      pr %= p;
      --b;
    }
    a *= a;
    a %= p;
    b /= 2;
  }
  return pr;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 or n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 or n % (i + 2) == 0) return false;
  }
  return true;
}
void seive(bool a[]) {
  long long mx = sqrt(N), ii, jj;
  for (ii = 3; ii <= mx; ii += 2)
    if (!a[ii])
      for (jj = ii * ii; jj <= N; jj += 2 * ii) a[jj] = true;
}
void numofdiv(long long a[]) {
  long long mx = sqrt(N), ii, jj;
  for (ii = 1; ii <= mx; ii++) {
    for (jj = ii * ii; jj <= N; jj += ii) {
      if (jj == ii * ii)
        a[jj]++;
      else
        a[jj] += 2;
    }
  }
}
void sumofdiv(long long a[]) {
  long long mx = sqrt(N), ii, jj;
  for (ii = 1; ii <= mx; ii++) {
    for (jj = ii * ii; jj <= N; jj += ii) {
      if (jj == ii * ii)
        a[jj] += ii;
      else
        a[jj] += ii + jj / ii;
    }
  }
}
int main() {
  long long n, t, i, sum = 1;
  cin >> n >> t;
  int cell[n + 5];
  cell[0] = 0;
  for (i = 1; i <= n - 1; i++) {
    cin >> cell[i];
  }
  bool ok = 0;
  i = 1;
  while (sum <= n) {
    sum = sum + cell[i];
    if (sum == t) {
      ok = 1;
      break;
    }
    i = sum;
  }
  if (ok == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
