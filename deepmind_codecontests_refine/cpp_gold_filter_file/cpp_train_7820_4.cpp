#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}
template <typename T, typename... U>
inline void read(T& x, U&... y) {
  read(x), read(y...);
}
const int N = 1e5 + 10;
int n, Q, P, cnt;
int V[9][N * 17], pri[9], sum[N << 2];
bool lazy[N << 2];
void ExGCD(int a, int b, int& x, int& y) {
  if (b)
    ExGCD(b, a % b, y, x), y -= a / b * x;
  else
    x = 1, y = 0;
}
int Inv(int a, int b) {
  int x, y;
  ExGCD(a, b, x, y);
  return (x % b + b) % b;
}
struct Data {
  int sum, num[9];
} A[N << 2];
void Pushup(int o) { sum[o] = (sum[o << 1] + sum[o << 1 | 1]) % P; }
void Build(int l, int r, int o) {
  A[o].sum = 1;
  if (l == r) {
    int a;
    read(a);
    int x = a;
    for (int i = 0; i < cnt; ++i) {
      int t = 0;
      while (x % pri[i] == 0) ++t, x /= pri[i];
      A[o].num[i] = t;
    }
    A[o].sum = x % P;
    sum[o] = a % P;
    return;
  }
  int mid = l + r >> 1;
  Build(l, mid, o << 1);
  Build(mid + 1, r, o << 1 | 1);
  Pushup(o);
}
void Down(int o, Data v) {
  for (int i = 0; i < cnt; ++i) A[o].num[i] += v.num[i];
  A[o].sum = 1ll * A[o].sum * v.sum % P;
  lazy[o] = true;
  int t = v.sum;
  for (int i = 0; i < cnt; ++i) t = 1ll * t * V[i][v.num[i]] % P;
  sum[o] = 1ll * sum[o] * t % P;
}
void Pushdown(int o) {
  if (lazy[o]) {
    Down(o << 1, A[o]);
    Down(o << 1 | 1, A[o]);
    for (int i = 0; i < cnt; ++i) A[o].num[i] = 0;
    A[o].sum = 1;
    lazy[o] = false;
  }
}
void Modify(int l, int r, int o, int ql, int qr, Data v) {
  if (ql <= l && r <= qr) return Down(o, v);
  Pushdown(o);
  int mid = l + r >> 1;
  if (ql <= mid) Modify(l, mid, o << 1, ql, qr, v);
  if (qr > mid) Modify(mid + 1, r, o << 1 | 1, ql, qr, v);
  Pushup(o);
}
void Modify(int l, int r, int o, int pos, int v) {
  if (l == r) {
    int x = v;
    for (int i = 0; i < cnt; ++i) {
      int t = 0;
      while (x % pri[i] == 0) ++t, x /= pri[i];
      A[o].num[i] -= t;
    }
    if (x != 1) A[o].sum = 1ll * A[o].sum * Inv(x % P, P) % P;
    sum[o] = A[o].sum;
    for (int i = 0; i < cnt; ++i) sum[o] = 1ll * sum[o] * V[i][A[o].num[i]] % P;
    return;
  }
  Pushdown(o);
  int mid = l + r >> 1;
  if (pos <= mid)
    Modify(l, mid, o << 1, pos, v);
  else
    Modify(mid + 1, r, o << 1 | 1, pos, v);
  Pushup(o);
}
int Query(int l, int r, int o, int ql, int qr) {
  if (ql <= l && r <= qr) return sum[o];
  Pushdown(o);
  int mid = l + r >> 1, t = 0;
  if (ql <= mid) t = Query(l, mid, o << 1, ql, qr);
  if (qr > mid) t = (t + Query(mid + 1, r, o << 1 | 1, ql, qr)) % P;
  Pushup(o);
  return t;
}
int main() {
  read(n, P);
  int x = P;
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) {
      pri[cnt++] = i;
      while (x % i == 0) x /= i;
    }
  if (x != 1) pri[cnt++] = x;
  Build(1, n, 1);
  read(Q);
  for (int i = 0; i < cnt; ++i) {
    V[i][0] = 1;
    for (int j = 1; j <= Q * 17; ++j) {
      V[i][j] = 1ll * V[i][j - 1] * pri[i] % P;
    }
  }
  while (Q--) {
    int opt, l, r, x;
    read(opt);
    if (opt == 1) {
      read(l, r, x);
      Data g;
      for (int i = 0; i < cnt; ++i) {
        int t = 0;
        while (x % pri[i] == 0) ++t, x /= pri[i];
        g.num[i] = t;
      }
      g.sum = x;
      Modify(1, n, 1, l, r, g);
    }
    if (opt == 2) {
      read(l, x);
      Modify(1, n, 1, l, x);
    }
    if (opt == 3) {
      read(l, r);
      printf("%d\n", Query(1, n, 1, l, r));
    }
  }
  return 0;
}
