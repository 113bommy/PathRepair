#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long b, long long p, long long m) {
  if (p == 0) return 1;
  long long my = bigmod(b, p / 2, m);
  my *= my;
  my %= m;
  if (p & 1) my *= b, my %= m;
  return my;
}
int setb(int n, int pos) { return n = n | (1 << pos); }
int resb(int n, int pos) { return n = n & ~(1 << pos); }
bool checkb(int n, int pos) { return (bool)(n & (1 << pos)); }
long long ara[505][505], lol[505][505];
long long n, a, b;
int main() {
  long long i, j;
  scanf("%lld %lld %lld", &n, &a, &b);
  for (i = 1; i <= a; i++) {
    long long cur = 1;
    if (ara[i - 1][1] == 1) cur = 0;
    for (j = 1; j <= b; j++) {
      ara[i][j] = cur;
      cur = 1 - cur;
    }
  }
  long long A, B;
  if (n & 1)
    A = n;
  else
    A = n - 1;
  if (n & 1)
    B = n - 1;
  else
    B = n;
  long long x = 1, y = 2;
  for (i = 1; i <= a; i++) {
    for (j = 1; j <= b; j++) {
      if (x <= A && ara[i][j] & 1) {
        lol[i][j] = x;
        x += 2;
      }
      if (y <= B && ara[i][j] % 2 == 0) {
        lol[i][j] = y;
        y += 2;
      }
    }
  }
  if (x > A && y > B) {
    for (i = 1; i <= a; i++) {
      for (j = 1; j <= b; j++) {
        if (j > 1) printf(" ");
        printf("%lld", lol[i][j]);
      }
      printf("\n");
    }
  } else
    puts("-1");
  return 0;
}
