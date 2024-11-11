#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, ff = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
  return sum * ff;
}
void write(long long x) {
  if (x < 0) x = ~(x - 1), putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void writesp(long long x) { write(x), putchar(' '); }
void writeln(long long x) { write(x), puts(""); }
const int mod = 1e9 + 7;
const int N = 3e6 + 7;
int n, a[N];
long long fac[N];
bool flag;
struct tree {
  long long hash1, hash2;
} t[N];
inline int ls(int root) { return root << 1; }
inline int rs(int root) { return root << 1 | 1; }
inline void push_up(int root, int len) {
  int mid = len >> 1;
  t[root].hash1 =
      (t[ls(root)].hash1 * fac[mid] % mod + t[rs(root)].hash1) % mod;
  t[root].hash2 =
      (t[ls(root)].hash2 + t[rs(root)].hash2 * fac[len - mid] % mod) % mod;
}
void modify(int root, int l, int r, int pos) {
  if (l == r) {
    t[root].hash1 = t[root].hash2 = 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= l)
    modify(ls(root), l, mid, pos);
  else
    modify(rs(root), mid + 1, r, pos);
  push_up(root, r - l + 1);
}
int query1(int root, int l, int r, int L, int R) {
  if (L > R) return 0;
  if (L == l && r == R) return t[root].hash1;
  int mid = (l + r) >> 1;
  if (R <= mid) return query1(ls(root), l, mid, L, R);
  if (L > mid) return query1(rs(root), mid + 1, r, L, R);
  return (query1(ls(root), l, mid, L, mid) * fac[R - mid] % mod +
          query1(rs(root), mid + 1, r, mid + 1, R)) %
         mod;
}
int query2(int root, int l, int r, int L, int R) {
  if (L > R) return 0;
  if (L == l && r == R) return t[root].hash2;
  int mid = (l + r) >> 1;
  if (R <= mid) return query2(ls(root), l, mid, L, R);
  if (L > mid) return query2(rs(root), mid + 1, r, L, R);
  return (query2(ls(root), l, mid, L, mid) +
          query2(rs(root), mid + 1, r, mid + 1, R) * fac[mid - l + 1] % mod) %
         mod;
}
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i) a[i] = read();
  fac[0] = 1;
  for (register int i = 1; i <= n; ++i) fac[i] = (fac[i - 1] * 3) % mod;
  for (register int i = 1; i <= n; ++i) {
    int diff = min(a[i] - 1, n - a[i]);
    if (query1(1, 1, n, a[i] - diff, a[i] - 1) !=
        query2(1, 1, n, a[i] + 1, a[i] + diff)) {
      flag = true;
      break;
    }
    modify(1, 1, n, a[i]);
  }
  if (flag)
    puts("YES");
  else
    puts("NO");
  return 0;
}
