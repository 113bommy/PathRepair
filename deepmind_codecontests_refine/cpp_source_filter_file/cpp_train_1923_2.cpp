#include <bits/stdc++.h>
int ww[1000000];
int c[1000000];
int a[1000000];
struct P {
  int w;
  int c;
};
P p[1000000];
int cmp(P a, P b) {
  if ((long long)a.c * b.w > (long long)b.c * a.w) return -1;
  if ((long long)a.c * b.w < (long long)b.c * a.w) return 1;
  return 0;
}
class Double {
  long long a, b;

 public:
  Double() {
    a = 0;
    b = 0;
  }
  Double(int p, int q, int t) {
    a = (long long)p * t / q;
    b = (long long)((double)((long long)(p * 1ll * t) % q) / q *
                    1000000000000000000);
  }
  Double operator=(Double c) {
    a = c.a;
    b = c.b;
    return *this;
  }
  Double operator+(Double c) {
    Double t;
    t = *this;
    t += c;
    return t;
  }
  Double operator*(int c) {
    Double t;
    t = *this;
    t *= c;
    return t;
  }
  Double operator*=(int c) {
    a *= c;
    long long t1 = b / 1000000000;
    long long t2 = b % 1000000000;
    a += t1 * c / 1000000000;
    b = t1 * c % 1000000000 * 1000000000;
    b += t2 * c;
  }
  Double operator+=(Double c) {
    a += c.a;
    b += c.b;
    a += b / 1000000000000000000;
    b %= 1000000000000000000;
    return *this;
  }
  void print() {
    if (1000000000000000000 - b < 1000000000) b = 0, a++;
    printf("%lld.", a);
    long long t = 1000000000000000000 / 10;
    for (int i = 0; i < 15; i++) {
      printf("%d", (int)(b / t));
      b %= t;
      t /= 10;
    }
  }
  Double operator+=(int c) {
    a += c;
    return *this;
  }
};
Double calc(int a, int b, int W) {
  P etalon = p[(a + b) / 2];
  if (a == b) {
    if (W == 0)
      return Double();
    else {
      Double t(W, p[a].w, p[a].c);
      return t;
    }
  }
  int ai = a;
  int bi = b;
  while (ai <= bi) {
    while (cmp(p[ai], etalon) == 1) ai++;
    while (cmp(p[bi], etalon) == -1) bi--;
    if (ai <= bi) {
      P t = p[ai];
      p[ai] = p[bi];
      p[bi] = t;
      ai++;
      bi--;
    }
  }
  int sum = 0;
  Double price;
  int c = bi;
  if (c < a) c = a;
  for (int i = a; i <= c; i++) {
    sum += p[i].w;
    price += p[i].c;
  }
  if (sum <= W) {
    price += calc(c + 1, b, W - sum);
    return price;
  }
  if (sum > W) {
    price = calc(a, c, W);
  }
  return price;
}
int main() {
  int n, m, w;
  scanf("%d%d%d", &n, &m, &w);
  for (int i = 0; i < m; i++) scanf("%d", &ww[i]);
  for (int i = 0; i < m; i++) scanf("%d", &c[i]);
  for (int i = 0; i < m; i++) scanf("%d", &a[i]);
  Double rez;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      p[j].c = c[j] - a[j] * i;
      p[j].w = ww[j];
    }
    rez += calc(0, m - 1, w);
  }
  rez.print();
}
