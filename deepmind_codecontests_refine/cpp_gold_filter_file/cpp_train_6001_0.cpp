#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long double PI = acos(-1);
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int mod1 = 998244353;
const long long INF = 2e18;
template <class T>
inline void amin(T &x, const T &y) {
  if (y < x) x = y;
}
template <class T>
inline void amax(T &x, const T &y) {
  if (x < y) x = y;
}
int read() {
  long long s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * f;
}
long long Pow(long long a, long long b) {
  if (a == 1 || b == 1) return a;
  if (b % 2 == 1) return (a * Pow(a, b - 1)) % MOD;
  return (Pow(a, b / 2) * Pow(a, b / 2)) % MOD;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  {
    int n, m;
    cin >> n >> m;
    string s;
    int way = 0;
    int x, y;
    string track[55];
    for (int i = 0; i < n; i++) {
      cin >> track[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (track[i][j] == 'S') {
          x = i;
          y = j;
        }
      }
    }
    cin >> s;
    int code[4] = {0, 1, 2, 3};
    do {
      int xc = x, yc = y;
      for (int i = 0; i < s.length(); i++) {
        int z = s[i] - '0';
        if (code[z] == 0)
          ++xc;
        else if (code[z] == 1)
          --xc;
        else if (code[z] == 2)
          ++yc;
        else {
          --yc;
        }
        if (xc < 0 || xc > (n - 1) || yc < 0 || yc > (m - 1) ||
            track[xc][yc] == '#') {
          break;
        } else if (track[xc][yc] == 'E') {
          ++way;
          break;
        }
      }
    } while (next_permutation(code, code + 4));
    cout << way << "\n";
  }
  return 0;
}
