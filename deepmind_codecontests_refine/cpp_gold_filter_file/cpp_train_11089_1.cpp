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
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
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
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
long long ModInverse(long long number, long long MOD) {
  return Bigmod(number, MOD - 2, MOD);
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
int toInt(string s) {
  int sm;
  stringstream second(s);
  second >> sm;
  return sm;
}
char s[100007];
char ans[100007];
int n, dp[100009][2][2];
int Solve(int l, int r, int cl, int cr) {
  if (l > r) {
    if ((l - r) == 2) return 1;
    if (cl == cr) return 1;
    return 0;
  }
  int &res = dp[l][cl][cr];
  if (res != -1) return dp[l][cl][cr];
  res = 0;
  int rgt = (s[r] - '0');
  int lft = (s[l] - '0');
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      if (l == 0 && (i == 0 && j == 0)) continue;
      if (l == r && i != j) continue;
      int now = (i + j + cr);
      if (now % 10 != (rgt)) continue;
      if (((i + j) / 10) == cl && ((i + j) % 10) == lft) {
        res |= Solve(l + 1, r - 1, 0, (now / 10));
        if (res == 1) {
          ans[l] = (char)(i + '0');
          ans[r] = (char)(j + '0');
          if (ans[l] == '0') swap(ans[l], ans[r]);
        }
      }
      now = i + j + 1;
      if ((now % 10) == lft && (now / 10) == cl) {
        res |= Solve(l + 1, r - 1, 1, (i + j + cr) / 10);
        if (res == 1) {
          ans[l] = (i + '0');
          ans[r] = (j + '0');
          if (ans[l] == '0') swap(ans[l], ans[r]);
        }
      }
      if (res) break;
    }
    if (res) break;
  }
  return res;
}
int main() {
  scanf("%s", &s);
  n = strlen(s);
  memset(dp, -1, sizeof(dp));
  int Fst = Solve(0, n - 1, 0, 0);
  if (Fst) {
    for (int i = 0; i < n; i++) printf("%c", ans[i]);
    printf("\n");
    return 0;
  }
  memset(dp, -1, sizeof(dp));
  int Scd = -1;
  if (s[0] == '1') {
    Scd = Solve(1, n - 1, 1, 0);
  }
  if (Scd == 1) {
    for (int i = 1; i < n; i++) printf("%c", ans[i]);
    printf("\n");
  } else {
    printf("0\n");
  }
  return 0;
}
