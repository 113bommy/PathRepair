#include <bits/stdc++.h>
using namespace std;
namespace FI {
const int SIZE = 1 << 18 | 1;
char buf[SIZE], *front, *back;
void Char(char &c) {
  if (front == back) back = (front = buf) + fread(buf, 1, SIZE, stdin);
  c = (front == back) ? (char)EOF : *front++;
}
template <typename T>
void Num(T &x) {
  char c;
  int f = 1;
  for (Char(c); c > '9' || c < '0'; Char(c))
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9'; Char(c)) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
}  // namespace FI
const int maxn = 1000 + 47;
int n, m, len, ha[maxn];
int a[maxn][maxn], mn[maxn][maxn], mx[maxn][maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) scanf("%d", &a[i][j]);
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++) ha[j] = a[i][j];
    sort(ha + 1, ha + m + 1);
    len = unique(ha + 1, ha + m + 1) - ha - 1;
    for (int j = (1); j <= (m); j++) {
      int now = lower_bound(ha + 1, ha + len + 1, a[i][j]) - ha;
      mn[i][j] = max(mn[i][j], now - 1);
      mx[i][j] = max(mx[i][j], len - now);
    }
  }
  for (int j = (1); j <= (m); j++) {
    for (int i = (1); i <= (n); i++) ha[i] = a[i][j];
    sort(ha + 1, ha + m + 1);
    len = unique(ha + 1, ha + m + 1) - ha - 1;
    for (int i = (1); i <= (n); i++) {
      int now = lower_bound(ha + 1, ha + len + 1, a[i][j]) - ha;
      mn[i][j] = max(mn[i][j], now - 1);
      mx[i][j] = max(mx[i][j], len - now);
    }
  }
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++) printf("%d ", mn[i][j] + mx[i][j] + 1);
    printf("\n");
  }
}
