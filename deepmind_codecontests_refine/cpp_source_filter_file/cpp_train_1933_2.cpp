#include <bits/stdc++.h>
using namespace std;
struct node {
  long long num, v, ans;
} query[1000010];
long long a[1000010], Q[1000010];
long long n, m, i, j, k, l, r, num;
long long read() {
  long long x = 0, k = 1;
  char c;
  while (!isdigit(c = getchar()))
    if (c == '-') k = -k;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c ^ 48);
  return x * k;
}
bool cmpv(node a, node b) { return a.v < b.v; }
bool cmpnum(node a, node b) { return a.num < b.num; }
void swap(long long &a, long long &b) {
  long long t = a;
  a = b;
  b = t;
}
void up(long long k) {
  for (long long i = k >> 1; i; k = i, i = i >> 1)
    if (Q[i] < Q[k])
      swap(Q[i], Q[k]);
    else
      return;
}
void down(long long k) {
  for (long long i = k << 1; i <= num; k = i, i = i << 1) {
    i += (i < num) & (Q[i] < Q[i + 1]);
    if (Q[i] > Q[k])
      swap(Q[i], Q[k]);
    else
      return;
  }
}
void ins(long long k) {
  Q[++num] = k;
  up(num);
}
void del() {
  Q[1] = Q[num--];
  down(num);
}
int main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= m; i++) query[i].v = read(), query[i].num = i;
  sort(query + 1, query + m + 1, cmpv);
  for (long long i = n; i >= 1; i--) {
    if (a[i] < 0) ins(a[i]);
    if (a[i] > 0)
      while (num && a[i]) {
        if (a[i] + Q[1] >= 0) {
          a[i] += Q[1];
          del();
        } else {
          Q[1] += a[i];
          a[i] = 0;
        }
      }
  }
  for (long long i = m; i >= 2; i--) query[i].v -= query[i - 1].v;
  for (long long i = 1; i <= m; i++) {
    while (num && query[i].v) {
      if (query[i].v + Q[1] >= 0) {
        query[i].v += Q[1];
        del();
      } else {
        Q[1] += query[i].v;
        query[i].v = 0;
      }
    }
    query[i].ans = num;
  }
  sort(query + 1, query + m + 1, cmpnum);
  for (long long i = 1; i <= m; i++) printf("%lld\n", query[i].ans);
  return 0;
}
