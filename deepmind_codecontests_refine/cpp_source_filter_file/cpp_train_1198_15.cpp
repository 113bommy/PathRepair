#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct que {
  int l, r, id;
  long long ans;
} q[N];
int block, s[N], tong[N * 10], k;
bool cmp1(que i, que j) {
  if (i.l / block != j.l / block) return i.l / block < j.l / block;
  return i.r < j.r;
}
bool cmp2(que i, que j) { return i.id < j.id; }
int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}
inline void print(long long x) {
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
long long ans = 0;
void add(int x) {
  ans += (long long)tong[s[x] ^ k];
  tong[s[x]]++;
}
void del(int x) {
  tong[s[x]]--;
  ans -= (long long)tong[s[x] ^ k];
}
int main() {
  int n, m, x;
  scanf("%d%d%d", &n, &m, &k);
  block = sqrt(n);
  for (int i = 1; i <= n; ++i) scanf("%d", &x), s[i] = s[i - 1] ^ x;
  for (int i = 1; i <= m; ++i)
    scanf("%d%d", &q[i].l, &q[i].r), q[i].l--, q[i].id = i;
  sort(q + 1, q + m + 1, cmp1);
  int l = 0, r = 0;
  tong[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (; l < q[i].l; l++) del(l);
    for (; l > q[i].l; l--) add(l - 1);
    for (; r < q[i].r; r++) add(r + 1);
    for (; r > q[i].r; r--) del(r);
    q[i].ans = ans;
  }
  sort(q + 1, q + m + 1, cmp2);
  for (int i = 1; i <= m; ++i) cout << q[i].ans << endl;
  return 0;
}
