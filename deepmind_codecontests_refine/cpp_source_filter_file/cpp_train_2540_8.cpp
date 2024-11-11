#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
template <class T>
T abs(T a) {
  return a >= 0 ? a : -a;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T mod(T a, T b) {
  return (a % b + b) % b;
}
template <class T>
T addmod(T a, T b, T c) {
  return (T)mod((long long)a + b, (long long)c);
}
template <class T>
T mulmod(T a, T b, T c) {
  return (T)mod((long long)a * b, (long long)c);
}
template <class T>
T powmod(T a, T b, T c) {
  return (T)mod(
      b ? mulmod(mod(sqr((long long)powmod(a, b >> 1, c)), (long long)c),
                 (b & 1LL) ? a : 1LL, (long long)c)
        : 1LL,
      (long long)c);
}
template <class T>
void maxe(T &a, T b) {
  a = max(a, b);
}
template <class T>
void mine(T &a, T b) {
  a = min(a, b);
}
template <class T>
void mode(T &a, T b) {
  a = mod(a, b);
}
template <class T>
void addmode(T &a, T b, T c) {
  a = addmod(a, b, c);
}
template <class T>
void mulmode(T &a, T b, T c) {
  a = mulmod(a, b, c);
}
template <class T>
void powmode(T &a, T b, T c) {
  a = powmod(a, b, c);
}
int iszero(double a) { return abs(a) <= eps; }
template <class T>
void geti(T &a) {
  a = 0;
  long long b = 1;
  char c = getchar();
  if (c == '-')
    b = -1;
  else
    a = c - 48;
  while ((c = getchar()) != ' ' && c != '\n') a = a * 10 + c - 48;
  a *= b;
}
void fileio_in_out() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
void fileio_txt() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void cal_Fact(int a, long long *fact) {
  fact[0] = 1;
  for (int i = 1; i <= a; i++) {
    fact[i] = i * fact[i - 1];
    fact[i] %= 1000000007;
  }
}
int n;
long long p[1005][1005];
int empty[1005], no[1005];
long long fact[1005];
int main() {
  cin >> n;
  cal_Fact(n, fact);
  for (int i = 1; i < (n + 1); ++i) {
    int x;
    cin >> x;
    if (x == -1)
      empty[i] = 1;
    else
      no[x] = 1;
  }
  int r = 0, w = 0;
  for (int x = 1; x < (n + 1); ++x)
    if (no[x] == 0 && empty[x])
      r++;
    else if (no[x] == 0 && empty[x] == 0)
      w++;
  for (int i = 1; i < (r + 1); ++i) {
    for (int j = 1; j < (i + 1); ++j) {
      p[w + i][j] = p[w + i][j - 1] + fact[w + i - 1] - p[w + i - 1][j - 1];
      p[w + i][j] = (p[w + i][j] + 1000000007) % 1000000007;
    }
  }
  if (r + w == w)
    cout << fact[w] << endl;
  else
    cout << (fact[r + w] - p[r + w][r] + 1000000007) % 1000000007 << endl;
  return 0;
}
