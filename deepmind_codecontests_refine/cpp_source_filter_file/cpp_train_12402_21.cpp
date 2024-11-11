#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, f = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar())
    sum = ((sum << 1) + (sum << 3) + (ch ^ 48));
  return f ? -sum : sum;
}
void write(const long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long n, m, a[550000], p[550000], sum;
struct node {
  long long l, r, i;
} q[550000];
bool cmp(node a, node b) {
  if (a.r == b.r) return a.l < b.l;
  return a.r < b.r;
}
void insert(long long x) {
  for (register long long i = (25); i >= (0); i--)
    if ((x >> i) & 1) {
      if (!p[i]) return p[i] = x, sum++, void();
      x ^= p[i];
    }
}
int main() {
  n = read();
  for (register long long i = (1); i <= (n); i++)
    a[i] = read(), a[i] ^= a[i - 1];
  if (!a[n]) return puts("-1"), 0;
  for (register long long i = (1); i <= (n); i++) insert(a[i]);
  write(sum), puts("");
}
