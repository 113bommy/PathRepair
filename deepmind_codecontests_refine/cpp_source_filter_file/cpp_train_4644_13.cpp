#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void out(long long x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) out(x / 10);
  putchar(x % 10 + '0');
}
inline void write(long long x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long ksm(long long a, long long b, long long p) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}
const int inf = 0x3f3f3f3f;
const int maxn = 6e6 + 7;
int tr[maxn][2], cnt[maxn], idx = 0;
void add(int x, int val) {
  int p = 0;
  for (int i = 30; i >= 0; i--) {
    int u = (x >> i & 1);
    if (val == 1) {
      if (tr[p][u] == 0) tr[p][u] = ++idx;
    }
    p = tr[p][u];
    cnt[p] += val;
  }
}
int qask(int x, int y) {
  int p = 0, sum = 0;
  for (int i = 30; i >= 0; i--) {
    int t = y >> i & 1, t1 = x >> i & 1;
    if (t)
      sum += cnt[tr[p][t1]], p = tr[p][t1 ^ 1];
    else
      p = tr[p][t1];
  }
  return sum;
}
int main() {
  int _ = read();
  while (_--) {
    int op = read();
    if (op == 1) {
      int x = read();
      add(x, 1);
    } else if (op == 2) {
      int x = read();
      add(x, -1);
    } else {
      int x = read(), y = read();
      cout << qask(x, y) << "\n";
    }
  }
  return 0;
}
