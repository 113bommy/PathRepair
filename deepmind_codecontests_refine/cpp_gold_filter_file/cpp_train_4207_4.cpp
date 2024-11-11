#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int Pow(int base, int n, int mo) {
  if (n == 0) return 1;
  if (n == 1) return base % mo;
  int tmp = Pow(base, n >> 1, mo);
  tmp = (long long)tmp * tmp % mo;
  if (n & 1) tmp = (long long)tmp * base % mo;
  return tmp;
}
int n;
int G[2000][2000], _G[2000][2000];
inline int pre(int x) { return (x - 2 + n) % n + 1; }
int main() {
  scanf("%d", &n);
  if (n == 4) {
    puts("-1");
    return 0;
  } else {
    for (int i = (1); i <= (n); ++i) G[i][i % n + 1] = 1;
    for (int i = (1); i <= (n); ++i)
      for (int j = i + 2; j <= n; j += 2)
        if (!G[j][i]) G[i][j] = 1;
    for (int i = (1); i <= (n); ++i)
      for (int j = (i + 1); j <= (n); ++j)
        if (!G[i][j] && !G[j][i]) G[j][i] = 1;
    for (int i = (1); i <= (n); ++i) {
      for (int j = (1); j <= (n); ++j) printf("%d ", G[i][j]);
      puts("");
    }
  }
  return 0;
}
