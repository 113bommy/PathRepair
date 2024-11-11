#include <bits/stdc++.h>
using namespace std;
float PHI = 1.6180339;
const float PI_F = 3.14159265358979f;
long long modpow(long long x, long long n, long long m) {
  if (n == 0) return 1 % m;
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
long long add(long long x, long long y) {
  x += y;
  if (x >= 1000000007) return x - 1000000007;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) return x + 1000000007;
  return x;
}
long long inv(long long a, long long m = 998244353) {
  return modpow(a, m - 2, m);
}
long long mul(long long a, long long b) { return (long long)a * b % 998244353; }
long long nCrModp(long long n, long long r, long long p) {
  long long C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
bool isPrime(long long n) {
  if (n <= 1) return true;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cout << fixed << setprecision(12);
  long long n;
  cin >> n;
  if (isPrime(n)) {
    cout << "1"
         << "\n";
    cout << "0"
         << "\n";
    return 0;
  }
  vector<long long> v;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
  }
  vector<long long> dp;
  vector<long long> np;
  for (long long i = 0; i < v.size(); i++) {
    if (isPrime(v[i])) {
      dp.push_back(v[i]);
    } else {
      np.push_back(v[i]);
    }
  }
  if (dp.size() == v.size()) {
    cout << "2"
         << "\n";
  } else {
    long long ans = -1;
    vector<long long> vec;
    for (long long i = 0; i < np.size(); i++) {
      vec.clear();
      long long cnt = 0;
      for (long long j = 2; j * j <= np[i]; j += 1) {
        if (np[i] % j == 0) {
          vec.push_back(j);
          vec.push_back(np[i] / j);
        }
      }
      for (long long j = 0; j < vec.size(); j++) {
        if (isPrime(vec[j]))
          ++cnt;
        else
          break;
      }
      if (cnt == vec.size()) {
        ans = np[i];
        break;
      }
    }
    if (ans == -1)
      cout << "2"
           << "\n";
    else {
      cout << "1"
           << "\n";
      cout << ans << "\n";
    }
  }
  return 0;
}
