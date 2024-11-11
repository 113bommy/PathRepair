#include <bits/stdc++.h>
using namespace std;
const int xx[] = {1, -1, 0, 0}, yy[] = {0, 0, 1, -1};
long long pow(long long a, long long b, long long p) {
  long long sum = 1;
  for (a %= p; b; a = a * a % p, b >>= 1)
    if (b & 1) sum = sum * a % p;
  return sum;
}
char ch;
void rd(int &x) {
  for (ch = getchar(); ch < '0'; ch = getchar())
    ;
  for (x = 0; ch >= '0'; ch = getchar()) x = x * 10 + ch - '0';
}
long long phi(long long n) {
  long long i, re = n;
  for (i = 2; i * i <= n; i++)
    if (n % i == 0) {
      re = re / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  if (n > 1) re = re / n * (n - 1);
  return re % 1000000007;
}
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= x * (a / b);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int T, n, m, x, y, i, j, o, k, a, b, Q, tot, w[222222];
long long c[222222], C[222222];
void add(int x, int z) {
  for (; x <= n; x += x & -x) c[x] += z;
}
void Add(int x, int z) {
  for (; x <= n; x += x & -x) C[x] += z;
}
long long qu(int x) {
  long long v = 0;
  for (; x; x -= x & -x) v += c[x];
  return v;
}
long long Qu(int x) {
  long long v = 0;
  for (; x; x -= x & -x) v += C[x];
  return v;
}
int main() {
  scanf("%d%d%d%d%d", &n, &k, &a, &b, &Q);
  for (; Q--;) {
    scanf("%d", &o);
    if (o == 1) {
      scanf("%d%d", &x, &y);
      if (w[x] > a)
        add(x, -a);
      else
        add(x, -w[x]);
      if (w[x] > b)
        Add(x, -b);
      else
        Add(x, -w[x]);
      w[x] += y;
      if (y > a)
        add(x, a);
      else
        add(x, w[x]);
      if (y > b)
        Add(x, b);
      else
        Add(x, w[x]);
    } else {
      scanf("%d", &x);
      printf("%I64d\n", Qu(x - 1) + (qu(n) - qu(x + k - 1)));
    }
  }
}
