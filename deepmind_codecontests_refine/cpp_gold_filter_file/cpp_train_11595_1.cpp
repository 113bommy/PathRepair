#include <bits/stdc++.h>
using namespace std;
const int maxbits = 5;
const int maxn = 1000000000;
struct data {
  long long bit[maxbits + 1];
};
void mul(data a, data b, data &c) {
  data t;
  memset(t.bit, 0, sizeof(t.bit));
  for (int i = 1; i <= maxbits / 2 + 1; ++i)
    for (int j = 1; j <= maxbits / 2 + 1; ++j) {
      t.bit[i + j - 1] += a.bit[i] * b.bit[j];
      t.bit[i + j] += t.bit[i + j - 1] / maxn;
      t.bit[i + j - 1] %= maxn;
    }
  c = t;
}
void add(data a, data b, data &c) {
  long long g = 0;
  memset(c.bit, 0, sizeof(c.bit));
  for (int i = 1; i <= maxbits; ++i) {
    c.bit[i] = a.bit[i] + b.bit[i] + g;
    g = c.bit[i] / maxn;
    c.bit[i] %= maxn;
  }
}
void del(data a, data b, data &c) {
  long long g = 0;
  memset(c.bit, 0, sizeof(c.bit));
  for (int i = 1; i <= maxbits; ++i) {
    c.bit[i] = a.bit[i] - b.bit[i] + g;
    if (c.bit[i] < 0) {
      c.bit[i] += maxn;
      g = -1;
    } else
      g = 0;
  }
}
void div(data a, long long b, data &c) {
  long long g = 0;
  memset(c.bit, 0, sizeof(c.bit));
  for (int i = maxbits; i >= 1; --i) {
    g = g * maxn + a.bit[i];
    c.bit[i] = g / b;
    g = g % b;
  }
}
void cha(long long a, data &b) {
  memset(b.bit, 0, sizeof(b.bit));
  b.bit[2] = a / maxn;
  b.bit[1] = a % maxn;
}
void sumsqu(long long x, data &a) {
  data X, T, temp, temp2, temp3;
  memset(T.bit, 0, sizeof(T.bit));
  T.bit[1] = 1;
  cha(x, X);
  add(X, T, temp);
  add(temp, X, temp2);
  mul(temp, temp2, temp3);
  mul(X, temp3, temp);
  div(temp, 6, temp);
  a = temp;
}
void g(long long x, long long y, data &a) {
  data X, Y, K, temp, temp2, fir, sec, thir;
  long long k;
  cha(x, X);
  cha(y, Y);
  if (x == y) {
    mul(X, X, temp);
    mul(temp, temp, temp2);
    add(temp, temp2, temp);
    div(temp, 2, fir);
    a = fir;
  } else if (x > y) {
    k = x - y;
    cha(k, K);
    mul(Y, Y, temp);
    mul(temp, temp, temp2);
    add(temp, temp2, temp);
    div(temp, 2, fir);
    mul(Y, Y, temp);
    del(temp, Y, temp2);
    div(temp2, 2, temp2);
    mul(temp2, K, sec);
    sumsqu(y + k, temp);
    sumsqu(y, temp2);
    del(temp, temp2, temp);
    mul(Y, temp, thir);
    del(fir, sec, temp);
    add(temp, thir, temp);
    a = temp;
  } else {
    k = y - x;
    cha(k, K);
    mul(X, X, temp);
    mul(temp, temp, temp2);
    add(temp, temp2, temp);
    div(temp, 2, fir);
    mul(X, X, temp);
    add(X, temp, temp2);
    div(temp2, 2, temp2);
    mul(temp2, K, sec);
    sumsqu(x + k - 1, temp);
    sumsqu(x - 1, temp2);
    del(temp, temp2, temp);
    mul(X, temp, thir);
    add(fir, sec, temp);
    add(temp, thir, temp);
    a = temp;
  }
}
void print_zero(long long a) {
  int i = 0, j;
  long long k = a;
  while (k != 0) {
    ++i;
    k /= 10;
  }
  for (j = 1; j <= 9 - i; ++j) printf("0");
  if (a != 0) printf("%I64d", a);
}
void print(data a) {
  int i;
  for (i = maxbits; i > 0; --i)
    if (a.bit[i] != 0) break;
  if (i > 1) {
    if ((a.bit[i] / 10 == 0) && (i == 2)) {
      if (a.bit[2] % 10 != 0) {
        i = a.bit[2] % 10;
        printf("%d", i);
        print_zero(a.bit[1]);
        printf("\n");
      } else
        printf("%I64d\n", a.bit[1]);
    } else {
      printf("...");
      i = a.bit[2] % 10;
      printf("%d", i);
      print_zero(a.bit[1]);
      printf("\n");
    }
  } else
    printf("%I64d\n", a.bit[1]);
}
void work() {
  long long x1, x2, y1, y2;
  scanf("%I64d %I64d %I64d %I64d", &x1, &y1, &x2, &y2);
  --x1;
  --y1;
  data a1, a2, a3, a4;
  g(x2, y2, a1);
  g(x1, y1, a2);
  g(x2, y1, a3);
  g(x1, y2, a4);
  add(a1, a2, a1);
  del(a1, a3, a1);
  del(a1, a4, a1);
  print(a1);
}
int main() {
  int test, i;
  scanf("%d", &test);
  for (i = 1; i <= test; ++i) work();
  return 0;
}
