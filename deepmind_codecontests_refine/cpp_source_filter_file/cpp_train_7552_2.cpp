#include <bits/stdc++.h>
using namespace std;
const long long Mo = 1000000007LL;
struct matrix {
  long long v[2][2];
  void operator*=(matrix b) {
    matrix a;
    memcpy(a.v, v, sizeof(v));
    memset(v, 0, sizeof(v));
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          v[i][j] += a.v[i][k] * b.v[k][j], v[i][j] %= Mo;
  }
  bool operator==(matrix b) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        if (v[i][j] != b.v[i][j]) return false;
    return true;
  }
} uni, mark[101000 << 2], trans, Trans;
struct str {
  long long a, b;
  void operator*=(matrix x) {
    long long a_ = a, b_ = b;
    a = a_ * x.v[0][0] + b_ * x.v[1][0];
    a %= Mo;
    b = a_ * x.v[0][1] + b_ * x.v[1][1];
    b %= Mo;
  }
} temp, val[101000 << 2];
str operator+(str a, str b) {
  return (str){(a.a + b.a) % Mo, (a.b + b.b) % Mo};
}
int n, m;
long long A[101000];
matrix fpm(long long b) {
  matrix ans = uni;
  matrix a = trans;
  for (; b; b >>= 1) {
    if (b & 1LL) ans *= a;
    a *= a;
  }
  return ans;
}
void build(int u, int L, int R) {
  mark[u] = uni;
  if (L == R) {
    val[u] = temp;
    val[u] *= fpm(A[L] - 1);
    return;
  }
  build((u << 1), L, ((L + R) >> 1));
  build(((u << 1) + 1), (((L + R) >> 1) + 1), R);
  val[u] = val[(u << 1)] + val[((u << 1) + 1)];
}
void down(int u, int L, int R) {
  if (mark[u] == uni) return;
  val[u] *= mark[u];
  if (L < R) {
    mark[(u << 1)] *= mark[u];
    mark[((u << 1) + 1)] *= mark[u];
  }
  mark[u] = uni;
  return;
}
void change(int u, int L, int R, int l, int r) {
  down(u, L, R);
  if (L == l && R == r) {
    val[u] *= Trans;
    down(u, L, R);
    return;
  }
  if (r < (((L + R) >> 1) + 1))
    down(((u << 1) + 1), (((L + R) >> 1) + 1), R),
        change((u << 1), L, ((L + R) >> 1), l, r);
  else if (l > ((L + R) >> 1))
    down((u << 1), L, ((L + R) >> 1)),
        change(((u << 1) + 1), (((L + R) >> 1) + 1), R, l, r);
  else
    change((u << 1), L, ((L + R) >> 1), l, ((L + R) >> 1)),
        change(((u << 1) + 1), (((L + R) >> 1) + 1), R, (((L + R) >> 1) + 1),
               r);
  val[u] = val[(u << 1)] + val[((u << 1) + 1)];
}
str find(int u, int L, int R, int l, int r) {
  down(u, L, R);
  if (L == l && R == r) return val[u];
  if (r < (((L + R) >> 1) + 1))
    return find((u << 1), L, ((L + R) >> 1), l, r);
  else if (l > ((L + R) >> 1))
    return find(((u << 1) + 1), (((L + R) >> 1) + 1), R, l, r);
  else {
    return find((u << 1), L, ((L + R) >> 1), l, ((L + R) >> 1)) +
           find(((u << 1) + 1), (((L + R) >> 1) + 1), R, (((L + R) >> 1) + 1),
                r);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  trans.v[1][1] = trans.v[0][1] = trans.v[1][0] = 1;
  uni.v[0][0] = uni.v[1][1] = 1;
  temp.a = 0;
  temp.b = 1;
  for (int i = 1; i <= n; i++) scanf("%I64d", &A[i]);
  build(1, 1, n);
  for (; m; m--) {
    int t, l, r, x;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      scanf("%d", &x);
      Trans = fpm(x);
      change(1, 1, n, l, r);
    } else {
      str u = find(1, 1, n, l, r);
      printf("%I64d\n", u.b);
    }
  }
  return 0;
}
