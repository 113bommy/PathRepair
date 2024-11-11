#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#pragma optimize("-O3")
inline long long read() {
  long long x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x = f ? -x : x;
}
inline void write(long long x, bool f) {
  if (x == 0) {
    putchar('0');
    if (f) putchar('\n');
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  static char s[23];
  int l = 0;
  while (x != 0) s[l++] = x % 10 + 48, x /= 10;
  while (l) putchar(s[--l]);
  if (f) putchar('\n');
}
constexpr int lowbit(int x) { return x & (-x); }
template <class T>
T big(const T &a1, const T &a2) {
  return a1 > a2 ? a1 : a2;
}
template <class T>
T sml(const T &a1, const T &a2) {
  return a1 < a2 ? a1 : a2;
}
template <typename T, typename... R>
T big(const T &f, const R &...r) {
  return big(f, big(r...));
}
template <typename T, typename... R>
T sml(const T &f, const R &...r) {
  return sml(f, sml(r...));
}
void debug_out() { cout << '\n'; }
template <typename T, typename... R>
void debug_out(const T &f, const R &...r) {
  cout << f << " ";
  debug_out(r...);
}
const char ptout[] = "%lld";
template <typename T>
void print(const T &f) {
  printf(ptout, f);
  putchar('\n');
}
template <typename T, typename... R>
void print(const T &f, const R &...r) {
  printf(ptout, f);
  putchar(' ');
  print(r...);
}
const int HMOD[] = {1000000009, 1004535809};
const long long BASE[] = {1572872831, 1971536491};
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MXN = 5e6 + 5;
const int MXE = 2e6 + 6;
int n, m;
int ans, LN;
int ar[MXN], F[MXN], resp[MXN];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    ar[i] = read();
    F[ar[i]] = 1;
    resp[ar[i]] = ar[i];
  }
  LN = 1 << 22;
  for (int i = 0; i < 22; ++i)
    for (int x = 0; x < LN; ++x) {
      if (x & (1 << i)) {
        F[x] += F[x ^ (1 << i)];
        if (resp[x ^ (1 << i)]) resp[x] = resp[x ^ (1 << i)];
      }
    }
  for (int i = 1; i <= n; ++i) {
    if (resp[(LN - 1) ^ ar[i]] == 0) resp[(LN - 1) ^ ar[i]] = -1;
    printf("%d ", resp[(LN - 1) ^ ar[i]]);
  }
  printf("\n");
  return 0;
}
