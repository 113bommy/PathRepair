#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = 1000010, P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int INF = 0xcfcfcfcf;
const double eps = 1e-9, pi = asin(1) * 2;
inline long long read();
inline int ADD(int a, int b) { return a + b >= P ? a + b - P : a + b; }
inline int MINUS(int a, int b) { return a - b < 0 ? a - b + P : a - b; }
struct XXJ {
  int a[N], v[N];
  inline void insert(int x) {
    int tmp = x;
    for (int i = 31; i >= 0; i--) {
      if (x & (1 << i)) {
        if (!a[i]) {
          a[i] = x, v[i] = tmp;
          return;
        } else
          x ^= a[i];
      }
    }
  }
} xxj;
int n;
int s[N];
bool visit[10000010];
inline long long read() {
  long long s = 0;
  bool flag = false;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') flag = true;
  for (; '0' <= ch && ch <= '9'; ch = getchar())
    s = (s << 3) + (s << 1) + (ch ^ '0');
  if (flag) return -s;
  return s;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) s[i] = read();
  sort(s + 1, s + n + 1);
  for (int i = 1; i <= n; i++) xxj.insert(s[i]);
  if (!xxj.a[0]) {
    printf("0\n0\n");
    return 0;
  }
  for (int i = 1; i <= 31; i++) {
    if (!xxj.a[i]) {
      while (i) {
        bool yes = true;
        for (int j = 0; j <= i; j++)
          if (xxj.v[j] >= (1 << i)) {
            yes = false;
            break;
          }
        if (yes) break;
        i--;
      }
    } else
      continue;
    printf("%d\n", i);
    int x = 0;
    for (int j = 0; j < (1 << i); j++) {
      printf("%d ", x), visit[x] = true;
      for (int k = 0; k <= i; k++)
        if (!visit[x ^ xxj.v[k]]) {
          x ^= xxj.v[k];
          break;
        }
    }
    return 0;
  }
  putchar('\n');
  return 0;
}
