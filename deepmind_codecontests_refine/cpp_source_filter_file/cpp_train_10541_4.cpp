#include <bits/stdc++.h>
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
inline T Bigmod(T b, T p, T m) {
  if (p == 0)
    return 1;
  else if (!(p & 1))
    return (Bigmod(b, p / 2, m) * Bigmod(b, p / 2, m)) % m;
  else
    return ((b % m) * Bigmod(b, p - 1, m)) % m;
}
template <typename T>
inline T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
inline T Dis(T x1, T y1, T x2, T y2) {
  return sqrt((x1 - x2 * x1 - x2) + (y1 - y2 * y1 - y2));
}
template <typename T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <typename T>
T ModInv(T b, T m) {
  return Bigmod(b, m - 2, m);
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
template <typename T>
T POW(T b, T p) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = POW(b, p / 2);
    return s * s;
  }
  return b * POW(b, p - 1);
}
using namespace std;
string s;
int k, len, store[502][502], dp[502][502], path[502][502];
int func(int st, int ed) {
  int mid = (st + ed) / 2, id = 0, cnt = 0;
  for (int i = st; i < mid + 1; i++) {
    if (s[i] != s[ed - id]) cnt++;
    id++;
  }
  return cnt;
}
void precal() {
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j++) {
      store[i][j] = func(i, j);
    }
  }
}
int solve(int pos, int koto) {
  if (pos == len) return 0;
  if (koto == 0) return (1 << 28);
  int &res = dp[pos][koto];
  if (res != -1) return res;
  res = (1 << 28);
  for (int i = pos; i < len; i++) {
    int tp = store[pos][i] + solve(i + 1, koto - 1);
    if (res > tp) {
      res = tp;
      path[pos][k] = i;
    }
  }
  return res;
}
void main_print(int st, int ed) {
  string tp;
  for (int i = st; i < ed + 1; i++) tp += s[i];
  int ln = tp.size();
  for (int i = 0; i < ln / 2 + 1; i++) {
    if (tp[i] != tp[ln - i - 1]) tp[i] = tp[ln - i - 1];
  }
  cout << tp;
  return;
}
void print_path(int pos, int koto) {
  if (pos == len) {
    printf("\n");
    return;
  }
  if (pos) printf("+");
  main_print(pos, path[pos][k]);
  print_path(path[pos][k] + 1, koto - 1);
  return;
}
int main() {
  cin >> s >> k;
  len = s.size();
  precal();
  memset(dp, -1, sizeof(dp));
  cout << solve(0, k) << endl;
  print_path(0, k);
  return 0;
}
