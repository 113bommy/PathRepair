#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int maxar(int arr[], int n) {
  int res = arr[0];
  for (int i = 0; i < n; i++) {
    res = max(res, arr[i]);
  }
  return res;
}
long long maxar(long long arr[], long long n) {
  long long res = arr[0];
  for (long long i = 0; i < n; i++) {
    res = max(res, arr[i]);
  }
  return res;
}
long long minar(long long arr[], long long n) {
  long long res = arr[0];
  for (long long i = 0; i < n; i++) {
    res = min(res, arr[i]);
  }
  return res;
}
int minar(int arr[], int n) {
  int res = arr[0];
  for (int i = 0; i < n; i++) {
    res = min(res, arr[i]);
  }
  return res;
}
void inpar(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}
void inpar(long long arr[], long long n) {
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
}
class extEuclidTriplet {
 public:
  long long x;
  long long y;
  long long gcd;
};
extEuclidTriplet gcdExtEuclidTriplet(long long a, long long b) {
  if (b == 0) {
    extEuclidTriplet base;
    base.x = 1;
    base.y = 0;
    base.gcd = a;
    return base;
  }
  extEuclidTriplet temp = gcdExtEuclidTriplet(b, a % b);
  extEuclidTriplet ans;
  ans.gcd = temp.gcd;
  ans.x = temp.y;
  ans.y = temp.x - ((a / b) * temp.y);
  return ans;
}
long long modInverse(long long a, long long b) {
  long long ans = gcdExtEuclidTriplet(a, b).x;
  return (ans % b + b) % b;
}
long long fact(long long n);
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  long long res = 1;
  if (r > n - r) {
    for (int i = r + 1; i <= n; i++) {
      res *= i;
      res %= 1000000007;
    }
    return res * (modInverse(fact(n - r), 1000000007) % 1000000007) %
           1000000007;
  } else {
    for (int i = n - r + 1; i <= n; i++) {
      res *= i;
      res %= 1000000007;
    }
    return res * (modInverse(fact(r), 1000000007) % 1000000007) % 1000000007;
  }
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) {
    res = res * i;
    res %= 1000000007;
  }
  return res % 1000000007;
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
const long long MAX_SIZE = 10000001;
vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);
void manipulated_seive(int N) {
  isprime[0] = isprime[1] = false;
  for (long long int i = 2; i < N; i++) {
    if (isprime[i]) {
      prime.push_back(i);
      SPF[i] = i;
    }
    for (long long int j = 0;
         j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {
      isprime[i * prime[j]] = false;
      SPF[i * prime[j]] = prime[j];
    }
  }
}
void solve() {
  int n = readInt<int>();
  int a[n];
  inpar(a, n);
  int sm = 0;
  for (int i : a) {
    sm += i;
  }
  if (sm % n) {
    cout << n;
    return;
  }
  cout << n - 1;
}
int32_t main() {
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
