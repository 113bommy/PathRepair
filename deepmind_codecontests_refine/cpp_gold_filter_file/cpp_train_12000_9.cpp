#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &n) {
  T w = 1;
  n = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != EOF) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch) && ch != EOF) {
    n = (n << 1) + (n << 3) + (ch ^ 48);
    ch = getchar();
  }
  n *= w;
}
template <typename T>
inline void write(T x) {
  long long y = 0;
  T l = 0;
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (!x) {
    putchar(48);
    return;
  }
  while (x) {
    y = y * 10 + x % 10;
    x /= 10;
    l++;
  }
  while (l) {
    putchar(y % 10 + 48);
    y /= 10;
    l--;
  }
}
template <typename T>
inline void writeln(T x) {
  write(x);
  puts("");
}
template <typename T>
inline void writes(T x) {
  write(x);
  putchar(' ');
}
template <typename T>
inline void checkmax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T>
inline void checkmin(T &a, T b) {
  a = a < b ? a : b;
}
long long a[50][50];
long long n, q;
void sol() {
  read(n);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i % 2 == 0) a[i][j] = 1ll << (i + j);
      cout << a[i][j] << " \n"[j == n - 1];
    }
  }
  fflush(stdout);
  read(q);
  for (long long i = 0; i < q; i++) {
    long long k;
    read(k);
    long long x = 0, y = 0;
    vector<array<long long, 2>> p;
    p.push_back({0, 0});
    k = (k - 1) / 2;
    for (long long j = 0; j < n + n - 2; j++) {
      if (x == n - 1)
        y++;
      else if (y == n - 1)
        x++;
      else {
        if (k % 2 == 1) {
          if (a[x + 1][y])
            x++;
          else
            y++;
        } else {
          if (a[x + 1][y])
            y++;
          else
            x++;
        }
      }
      if (a[x][y]) k -= 1;
      k /= 2;
      p.push_back({x, y});
    }
    for (auto cor : p) cout << cor[0] + 1 << " " << cor[1] + 1 << endl;
    fflush(stdout);
  }
}
int32_t main() {
  long long t;
  t = 1;
  while (t--) {
    sol();
  }
  return 0;
}
