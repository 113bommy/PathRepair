#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
inline long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
inline long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
inline long long int add(long long int a, long long int b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}
inline long long int multi(long long int a, long long int b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
inline long long int sub(long long int a, long long int b) {
  a %= MOD;
  b %= MOD;
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
inline long long int power(long long int a, long long int b) {
  a %= MOD;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = multi(res, a);
    }
    a = multi(a, a);
    b >>= 1;
  }
  return res;
}
bool isPrime(long long int x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) {
    return x == 2 || x == 3;
  }
  for (long long int i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) {
      return 0;
    }
  }
  return 1;
}
long long int XOR(long long int a, long long int b, long long int c) {
  return a ^ b ^ c;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int arr[n];
  long long int x = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    x ^= arr[i];
  }
  long long int m = 0;
  vector<long long int> res;
  if (n % 2 == 0 && x != 0) {
    cout << "NO";
    return 0;
  } else {
    if (n % 2 == 0) n--;
    for (long long int i = 0; i < n - 2; i += 2) {
      arr[i] = arr[i + 1] = arr[i + 2] = XOR(arr[i], arr[i + 1], arr[i + 2]);
      for (long long int j = 1; j <= 3; j++) res.push_back(i + j);
      m++;
    }
    for (long long int i = n - 3; i >= 2; i -= 2) {
      arr[i] = arr[i - 1] = arr[i - 2] = XOR(arr[i], arr[i - 1], arr[i - 2]);
      for (long long int j = 0; j < 3; j++) res.push_back(i - j + 1);
      m++;
    }
    cout << "YES\n" << m << endl;
    for (long long int i = 0; i < ((long long int)(res).size()); i += 3) {
      cout << res[i] << " " << res[i + 1] << " " << res[i + 2] << endl;
    }
  }
}
