#include <bits/stdc++.h>
using namespace std;
struct node {
  int p, a, r;
};
struct node1 {
  long long a, r;
} a[110000], A[110000], B[110000];
int n, m, ans, num1, num2;
long long mmod;
vector<node> v[110000];
long long multi(long long a, long long b) {
  long long t = 0;
  a %= mmod;
  b %= mmod;
  while (b) {
    if (b % 2) t = (t + a) % mmod;
    b /= 2;
    a = a * 2ll % mmod;
  }
  return t;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long g, xx, yy, t;
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  t = a / b;
  g = exgcd(b, a % b, xx, yy);
  x = yy;
  y = xx - t * yy;
  return g;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
node1 comb(node1 t1, node1 t2) {
  node1 t;
  t.a = -1;
  long long r = t2.r - t1.r, x, y, g;
  g = gcd(t1.a, t2.a);
  mmod = t2.a / g;
  g = exgcd(t1.a, t2.a, x, y);
  if (r % g) return t;
  t.a = t1.a / g * t2.a;
  mmod = t.a;
  x = multi(r / g, x);
  t.r = (t1.r + multi(x, t1.a)) % mmod;
  t.r = (t.r + mmod) % mmod;
  return t;
}
void cdq(int l, int r) {
  if (r - l + 1 <= ans) return;
  if (l == r) {
    ans = 1;
    return;
  }
  int mid = (l + r) / 2;
  cdq(l, mid);
  cdq(mid + 1, r);
  num1 = 1;
  A[num1] = a[mid];
  for (int i = mid - 1; i >= l; i--) {
    node1 t = comb(A[num1], a[i]);
    if (t.a == -1) break;
    A[++num1] = t;
  }
  num2 = 1;
  B[num2] = a[mid + 1];
  for (int i = mid + 2; i <= r; i++) {
    node1 t = comb(B[num2], a[i]);
    if (t.a == -1) break;
    B[++num2] = t;
  }
  int j = num2;
  for (int i = 1; i <= num1; i++) {
    while (j) {
      node1 t = comb(A[i], B[j]);
      if (t.a == -1)
        j--;
      else
        break;
    }
    if (j == 0) break;
    ans = max(ans, i + j);
  }
}
void solve(int now) {
  int num = 0, siz = v[now].size(), pre = -1;
  ans = 0;
  for (int i = 0; i < siz; i++) {
    if (v[now][i].p != pre + 1) {
      if (pre != -1 && num > ans) cdq(1, num);
      num = 1;
    } else
      num++;
    a[num].a = v[now][i].a;
    a[num].r = v[now][i].r;
    pre = v[now][i].p;
  }
  cdq(1, num);
  printf("%d\n", ans);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    for (int j = 1; j <= a; j++) {
      int x;
      scanf("%d", &x);
      v[x].push_back((node){i, a, j % a});
    }
  }
  for (int i = 1; i <= m; i++) solve(i);
  return 0;
}
