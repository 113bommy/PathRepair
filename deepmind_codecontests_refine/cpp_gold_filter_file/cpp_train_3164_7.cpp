#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x > y ? y : x;
}
template <typename T>
void update(T &x, T y, T mod) {
  x = x + y > mod ? x + y - mod : x + y;
}
const int INF = (1ll << 30);
template <typename T>
void read(T &x) {
  x = 0;
  bool f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = 0;
  } while (ch > '9' || ch < '0');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  x = f ? x : -x;
}
template <typename T>
void write(T x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1000 + 5;
int n, m, k, cnt, a[N][N];
char v[N][N], h[N][N];
int main() {
  read(n);
  read(m);
  read(k);
  int sum = n * (m - 1) + (n - 1) * m;
  for (int i = 0; i < n; i++) {
    scanf("%s", h[i]);
    for (int j = 0; j < m - 1; j++) cnt += h[i][j] == 'E';
    if (i < n - 1) {
      scanf("%s", v[i]);
      for (int j = 0; j < m; j++) cnt += v[i][j] == 'E';
    }
  }
  if (k == 1) {
    if (cnt * 4 < sum * 3) return puts("NO"), 0;
    puts("YES");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        printf("1 ");
      }
      puts("");
    }
    return 0;
  }
  puts("YES");
  bool flag = true;
  if (n > m) {
    flag = false;
    swap(n, m);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        swap(h[i][j], v[j][i]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 1; j < m; j++)
      if (h[i][j - 1] == 'N')
        a[i][j] = (!a[i][j - 1]);
      else
        a[i][j] = a[i][j - 1];
    if (i)
      for (int j = 0; j < m; j++)
        cnt += (v[i - 1][j] == 'E') != (a[i - 1][j] == a[i][j]);
    if (cnt * 2 >= m)
      for (int j = 0; j < m; j++) a[i][j] ^= 1;
  }
  if (flag) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d ", a[i][j] + 1);
      }
      puts("");
    }
  } else {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ", a[j][i] + 1);
      }
      puts("");
    }
  }
  return 0;
}
