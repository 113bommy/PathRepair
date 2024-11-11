#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
struct Node {
  int op, pos, n, m;
} a[200100];
int cnt, num[100100];
long long ans[200], v[200];
void gcd(long long a, long long b, long long& d, long long& x, long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inv(long long a, long long n) {
  long long d, x, y;
  gcd(a, n, d, x, y);
  return d == 1 ? (x + n) % n : -1;
}
void addNode(int op, int pos, int n, int m) {
  a[cnt].op = op;
  a[cnt].pos = pos;
  a[cnt].n = n;
  a[cnt++].m = m;
}
int cmp(Node a, Node b) {
  if (a.pos == b.pos)
    return a.op < b.op;
  else
    return a.pos < b.pos;
}
void init() {
  for (int i = 1; i <= 120; i++) v[i] = inv(i, MOD);
}
int main() {
  init();
  int n, tt;
  scanf("%d%d", &n, &tt);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  cnt = 0;
  while (tt--) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    addNode(0, l, k, k);
    addNode(1, r, r - l + k, k);
  }
  sort(a, a + cnt, cmp);
  memset(ans, 0, sizeof(ans));
  int head = 0;
  for (int i = 1; i <= n; i++) {
    while (head < cnt && a[head].pos == i && a[head].op == 0) {
      long long nn = a[head].n;
      long long mm = a[head].m;
      long long t = 1;
      int j = 1;
      while (mm >= 0) {
        ans[mm] += t;
        ans[mm] %= MOD;
        t = ((t * nn) % MOD * v[j]) % MOD;
        mm--;
        nn--;
        j++;
      }
      head++;
    }
    printf("%d ", (ans[0] + num[i]) % MOD);
    while (head < cnt && a[head].pos == i && a[head].op == 1) {
      long long nn = a[head].n;
      long long mm = a[head].m;
      long long t = 1;
      int j = 1;
      while (mm >= 0) {
        ans[mm] = ans[mm] + MOD - t;
        ans[mm] %= MOD;
        t = ((t * nn) % MOD * v[j]) % MOD;
        mm--;
        nn--;
        j++;
      }
      head++;
    }
    int j = 0;
    while (ans[j] > 0) {
      ans[j] = ans[j] + ans[j + 1];
      j++;
    }
  }
}
