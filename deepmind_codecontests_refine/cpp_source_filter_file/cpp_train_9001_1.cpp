#include <bits/stdc++.h>
using namespace std;
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
inline T Dis(T x1, T y1, T x2, T y2) {
  return sqrt((x1 - x2 * x1 - x2) + (y1 - y2 * y1 - y2));
}
template <typename T>
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
}
template <typename T>
inline T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
inline T Gcd(T a, T b) {
  if (a < 0) return Gcd(-a, b);
  if (b < 0) return Gcd(a, -b);
  return (b == 0) ? a : Gcd(b, a % b);
}
template <typename T>
inline T Lcm(T a, T b) {
  if (a < 0) return Lcm(-a, b);
  if (b < 0) return Lcm(a, -b);
  return a * (b / Gcd(a, b));
}
long long Bigmod(long long base, long long power, long long MOD) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
long long ModInverse(long long number, long long MOD) {
  return Bigmod(number, MOD - 2, MOD);
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }
bool Chkbit(int N, int pos) { return (bool)(N & (1 << pos)); }
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
int toInt(string s) {
  int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
long long int toLlint(string s) {
  long long int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
long long int ar[3100007];
int Start[3100007];
int main() {
  int n, m, N;
  n = in<int>(), m = in<int>();
  N = 2 * n;
  for (int i = 1; i < n + 1; i++) ar[i] = in<long long int>();
  for (int i = 1; i < n + 1; i++) ar[i + n] = ar[i];
  for (int i = 1; i < n + 1; i++) ar[i + N] = ar[i];
  N += n;
  ar[N + 1] = 1000000000000000000;
  while (m--) {
    long long int a;
    a = in<long long int>();
    int lft = 1, rgt = 1;
    long long int now = 0;
    int mx = 100000000, id;
    long long int Last = 0;
    while (true) {
      if (now + ar[rgt] <= a) {
        now += ar[rgt];
        rgt++;
      } else {
        Start[lft] = rgt - lft;
        if (lft <= n) {
          if (Start[lft] < mx) {
            mx = Start[lft];
            id = lft;
            Last = now;
          } else if (mx == Start[lft]) {
            if (now > Last) {
              mx = Start[lft];
              id = lft;
              Last = now;
            }
          }
        }
        now -= ar[lft];
        lft++;
      }
      if (lft == rgt && lft == N + 1) break;
    }
    if (Start[id] >= n) {
      printf("1\n");
      continue;
    }
    int r = id + Start[id] - 1, ans = 100000000;
    for (int i = max(1, id - 1); i <= r; i++) {
      int Tot = 0;
      for (int j = i; j < i + n; j += Start[j]) {
        Tot++;
      }
      ans = min(ans, Tot);
    }
    printf("%d\n", ans);
  }
  return 0;
}
