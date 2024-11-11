#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long int INF = INT_MAX, NINF = INT_MIN;
const long long int mod = 1e9 + 7;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
void print(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << '\n';
}
template <typename T>
void print(vector<vector<T>>& v) {
  for (vector<T>& vv : v) {
    for (T& i : vv) cout << i << " ";
    cout << '\n';
  }
}
template <typename T>
void read(vector<T>& v) {
  for (T& i : v) cin >> i;
}
template <typename T>
void read(T&& t) {
  cin >> t;
}
template <typename T, typename... Args>
void read(T&& t, Args&&... args) {
  cin >> t;
  read(forward<Args>(args)...);
}
template <typename T>
void print(T&& t) {
  cout << t << '\n';
}
template <typename T, typename... Args>
void print(T&& t, Args&&... args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
bool isPrime(ll n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (ll i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
ll binpow(ll a, ll b, ll mod) {
  a %= mod;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
ll to_int(string str) {
  ll n = str.size(), num = 0;
  for (int i = 0; i < n; i++) {
    num = num * 10 + (str[i] - '0');
  }
  return num;
}
ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll sumofDigits(ll n) {
  ll sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
bool isPalindrome(string str) {
  int n = str.size();
  for (int i = 0; i < n; i++) {
    if (str[i] != str[n - i - 1]) {
      return false;
    }
  }
  return true;
}
string toBinary(ll n) {
  string str = "";
  while (n > 0) {
    str += n % 2 + '0';
    n /= 2;
  }
  reverse(str.begin(), str.end());
  return str;
}
ll toDecimal(string str) {
  ll n = str.size(), ans = 0;
  for (ll i = n - 1; i >= 0; i--) {
    if (str[i] == '1') {
      ans += pow(2, n - i - 1);
    }
  }
  return ans;
}
ll modInverse(ll n, ll mod) { return binpow(n, mod - 2, mod); }
ll C(ll n, ll r, ll p) {
  if (r == 0 or n == r) return 1;
  ll fac[n + 1];
  fac[0] = 1;
  for (ll i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= p;
  }
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
vector<int> storePrimes;
void seive() {
  map<int, int> is_prime;
  for (int i = 2; i * i <= 100000; i++) {
    if (is_prime[i] == 0)
      for (int j = i * i; j <= 100000; j += i) {
        is_prime[j] = 1;
      }
  }
  for (int i = 2; i <= 100000; i++) {
    if (is_prime[i] == 0) {
      storePrimes.push_back(i);
    }
  }
}
bool isPowerof2(ll n) {
  if ((n & (n - 1)) == 0) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  ll n, m, k;
  cin >> n >> m >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  ll a = arr[n - 1];
  ll b = arr[n - 2];
  ll take = b / k + 1;
  ll ans = a * (m - take) + b * take;
  print(ans);
}
