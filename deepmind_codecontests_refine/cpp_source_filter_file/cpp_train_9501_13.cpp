#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double eps = 1e-11;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long mul(long long a, long long b) {
  long long ans = 0;
  a %= mod, b %= mod;
  while (b) {
    if (b & 1) ans = (ans + a) % mod;
    a = (a * 2) % mod;
    b >>= 1;
  }
  return ans;
}
long long powmod(long long a, long long b) {
  long long ans = 1;
  a %= mod;
  b %= (mod - 1);
  while (b) {
    if (b & 1) {
      ans = ans * a % mod;
      b--;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
int pr(long long num) {
  if (num == 1) return 0;
  if (num == 2 || num == 3) return 1;
  if (num % 6 != 1 && num % 6 != 5) return 0;
  int tmp = sqrt(num);
  for (int i = 5; i <= tmp; i += 6)
    if (num % i == 0 || num % (i + 2) == 0) return 0;
  return 1;
}
int Day(int y, int m, int d) {
  if (m == 1 || m == 2) {
    m += 12;
    y--;
  }
  int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
  return w + 1;
}
long long C(long long n, long long m) {
  if (n < m) return 0;
  long long res = 1;
  for (int i = 1; i <= m; i++) {
    long long a = (n + i - m) % mod;
    long long b = i % mod;
    res = res * (a * powmod(b, mod - 2) % mod) % mod;
  }
  return res;
}
long long Lucas(long long n, long long m) {
  if (m == 0) return 1;
  return C(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
}
long long PRIMES[223] = {
    2,    3,    5,    7,    11,   13,   17,   19,   23,   29,   31,   37,
    41,   43,   47,   53,   59,   61,   67,   71,   73,   79,   83,   89,
    97,   101,  103,  107,  109,  113,  127,  131,  137,  139,  149,  151,
    157,  163,  167,  173,  179,  181,  191,  193,  197,  199,  211,  223,
    227,  229,  233,  239,  241,  251,  257,  263,  269,  271,  277,  281,
    283,  293,  307,  311,  313,  317,  331,  337,  347,  349,  353,  359,
    367,  373,  379,  383,  389,  397,  401,  409,  419,  421,  431,  433,
    439,  443,  449,  457,  461,  463,  467,  479,  487,  491,  499,  503,
    509,  521,  523,  541,  547,  557,  563,  569,  571,  577,  587,  593,
    599,  601,  607,  613,  617,  619,  631,  641,  643,  647,  653,  659,
    661,  673,  677,  683,  691,  701,  709,  719,  727,  733,  739,  743,
    751,  757,  761,  769,  773,  787,  797,  809,  811,  821,  823,  827,
    829,  839,  853,  857,  859,  863,  877,  881,  883,  887,  907,  911,
    919,  929,  937,  941,  947,  953,  967,  971,  977,  983,  991,  997,
    1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,
    1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163,
    1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249,
    1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321,
    1327, 1361, 1367, 1373, 1381, 1399, 1409};
const int maxn = 2e6 + 5;
long long a[maxn];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int pos = -1;
    for (int i = 0; i <= n - 1; i++) {
      if (s[i] != s[n - 1]) {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      cout << n / 3 + 1 << '\n';
    } else {
      long long ans = 0;
      s += string(pos, s[n - 1]);
      s.erase(0, pos);
      for (int i = 0; i <= n - 1; i++) {
        int cnt = 1;
        int j;
        for (j = i + 1; j < n; ++j) {
          if (s[i] == s[j])
            cnt++;
          else {
            i = j - 1;
            break;
          }
        }
        ans += cnt / 3;
        if (j == n) break;
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
