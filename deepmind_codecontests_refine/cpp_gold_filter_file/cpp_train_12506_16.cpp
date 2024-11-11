#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void ZZ(const char* name, Arg1&& arg1) {
  std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " = " << arg1;
  ZZ(comma, args...);
}
const long long INF = 0xFFFFFFFFFFFFFFFL;
clock_t time_p = clock();
void timedekhlo() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
long long seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long rnd(long long l = 0, long long r = INF) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
long long modpow(long long x, long long y, long long m) {
  long long res = 1;
  x = x % m;
  while (y > 0) {
    if (y & 1) res = ((res % m) * (x % m)) % m;
    y = y >> 1;
    x = ((x % m) * (x % m)) % m;
  }
  return res % m;
}
long long modinv(long long x, long long m) { return modpow(x, m - 2, m); }
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool isvowel(char c) {
  return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'I' ||
          c == 'i' || c == 'U' || c == 'u' || c == 'O' || c == 'o');
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 2) {
      if (s[0] >= s[1])
        cout << "NO" << endl;
      else
        cout << "YES\n2" << endl << s[0] << " " << s[1] << endl;
      continue;
    }
    cout << "YES\n2" << endl;
    cout << s[0] << " ";
    for (long long i = 0; i < n - 1; i++) cout << s[i + 1];
    cout << endl;
  }
  timedekhlo();
  return 0;
}
