#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  long long f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long Power(long long a, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n % 2 != 0) {
      res = ((res % mod) * (a % mod)) % mod;
      n--;
    } else {
      a = ((a % mod) * (a % mod)) % mod;
      n /= 2;
    }
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long getSum(long long n) {
  long long sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
long long myceil(long long n, long long x) {
  long long y;
  if (n % x == 0) {
    y = n / x;
    return y;
  } else {
    y = n / x + 1;
    return y;
  }
}
long long primes[1300000];
void Sieve() {
  bool IsPrime[1300000];
  memset(IsPrime, true, sizeof(IsPrime));
  for (long long p = 2; p * p < 1300000; p++) {
    if (IsPrime[p] == true) {
      for (long long i = p * p; i < 1300000; i += p) IsPrime[i] = false;
    }
  }
  long long index = 0;
  for (long long p = 2; p < 1300000; p++)
    if (IsPrime[p]) {
      primes[index] = p;
      index++;
    }
}
void q1();
void q2();
void q3();
void q4();
void q5();
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  q5();
}
void q1() {
  long long n, a, b;
  cin >> n >> a >> b;
  cout << min(n - a, b + 1) << "\n";
}
void q2() {
  string s;
  cin >> s;
  long long n = s.length();
  bool set = true;
  for (long long i = 0; i < n; i++) {
    long long j = i;
    long long cnt = 0;
    while (j < n && s[j] == s[i]) {
      cnt++;
      j++;
    }
    if (cnt >= 7) {
      set = false;
      break;
    }
    i = j - 1;
  }
  if (!set) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
void q3() {
  string s;
  cin >> s;
  long long n = s.length();
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == 'y') {
      continue;
    } else {
      cout << "." << s[i];
    }
  }
  cout << "\n";
}
void q4() {
  long long n;
  cin >> n;
  cout << n << " ";
  for (long long i = 1; i <= n - 1; i++) cout << i << " ";
}
void q5() {
  long long n;
  cin >> n;
  long long w = 0;
  for (long long i = 0; i <= 2 * n; i++) {
    long long k = 1;
    for (long long j = 1; j <= 2 * n + 1 + 2 * w; j++) {
      if (k + 2 * w >= 2 * n + 1 && k % 2 != 0) {
        cout << (k + 2 * w - 2 * n) / 2;
      } else {
        cout << " ";
      }
      if (j <= 2 * n) {
        k++;
      } else {
        k--;
      }
    }
    cout << "\n";
    if (i < n) {
      w++;
    } else {
      w--;
    }
  }
}
