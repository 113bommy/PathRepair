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
int n, m, q, dp[1002][1002][4], ar[1002][1002];
void Update(int x, int y) {
  ar[x][y] ^= 1;
  for (int i = x; i <= n; i++) {
    if (ar[i][y]) {
      dp[i][y][0] = dp[i - 1][y][0] + 1;
    } else
      dp[i][y][0] = 0;
  }
  for (int i = x; i > 0; i--) {
    if (ar[i][y]) {
      dp[i][y][1] = dp[i + 1][y][1] + 1;
    } else
      dp[i][y][1] = 0;
  }
  for (int i = y; i <= m; i++) {
    if (ar[x][i]) {
      dp[x][i][2] = dp[x][i - 1][2] + 1;
    } else {
      dp[x][i][2] = 0;
    }
  }
  for (int i = y; i > 0; i--) {
    if (ar[x][i]) {
      dp[x][i][3] = dp[x][i + 1][3] + 1;
    } else {
      dp[x][i][3] = 0;
    }
  }
  return;
}
int Solve(int x, int y) {
  int ans = 0;
  int l, r;
  int mn;
  l = y, r = y;
  mn = (1 << 28);
  while (true) {
    if (dp[x][l][0] && dp[x][l][0] > dp[x][r][0]) {
      mn = min(mn, dp[x][l][0]);
      l--;
    } else if (dp[x][r][0]) {
      mn = min(mn, dp[x][r][0]);
      r++;
    } else
      break;
    ans = max(ans, (r - l - 1) * mn);
  }
  l = y, r = y;
  mn = (1 << 28);
  while (true) {
    if (dp[x][l][1] && dp[x][l][1] > dp[x][r][1]) {
      mn = min(mn, dp[x][l][1]);
      l--;
    } else if (dp[x][r][1]) {
      mn = min(mn, dp[x][r][1]);
      r++;
    } else
      break;
    ans = max(ans, (r - l - 1) * mn);
  }
  l = x, r = x;
  mn = (1 << 28);
  while (true) {
    if (dp[l][y][2] && dp[l][y][2] > dp[r][y][2]) {
      mn = min(mn, dp[l][y][2]);
      l--;
    } else if (dp[r][y][2]) {
      mn = min(mn, dp[r][y][2]);
      r++;
    } else
      break;
    ans = max(ans, (r - l - 1) * mn);
  }
  l = x, r = x;
  mn = (1 << 28);
  while (true) {
    if (dp[l][y][3] && dp[l][y][3] > dp[r][y][3]) {
      mn = min(mn, dp[l][y][3]);
      l--;
    } else if (dp[r][y][3]) {
      mn = min(mn, dp[r][y][3]);
      r++;
    } else
      break;
    ans = max(ans, (r - l - 1) * mn);
  }
  return ans;
}
int main() {
  n = in<int>(), m = in<int>(), q = in<int>();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ar[i][j] = in<int>();
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (ar[j][i]) dp[j][i][0] = dp[j - 1][i][0] + 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = n; j > 0; j--) {
      if (ar[j][i]) dp[j][i][1] = dp[j + 1][i][1] + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ar[i][j]) dp[i][j][2] = dp[i][j - 1][2] + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j > 0; j--) {
      if (ar[i][j]) dp[i][j][3] = dp[i][j + 1][3] + 1;
    }
  }
  while (q--) {
    int id, x, y;
    id = in<int>(), x = in<int>(), y = in<int>();
    if (id == 1) {
      Update(x, y);
    } else {
      printf("%d\n", Solve(x, y));
    }
  }
  return 0;
}
