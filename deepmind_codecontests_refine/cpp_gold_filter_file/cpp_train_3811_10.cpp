#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
struct bit {
  int a[maxn];
  int lowbit(int x) { return x & (-x); }
  void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i)) {
      a[i] += v;
    }
  }
  int get(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i)) {
      sum += a[i];
    }
    return sum;
  }
  int get(int l, int r) { return get(r) - get(l - 1); }
} T[11][11][4];
char s[maxn];
int q;
int getid(char x) {
  if (x == 'A') return 0;
  if (x == 'T') return 1;
  if (x == 'C') return 2;
  if (x == 'G') return 3;
}
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  for (int j = 1; j <= 10; j++)
    for (int i = 1; i <= len; i++) T[j][i % j][getid(s[i])].update(i, 1);
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int l;
      char t[10];
      scanf("%d%s", &l, t);
      for (int i = 1; i <= 10; i++) {
        T[i][l % i][getid(t[0])].update(l, 1);
        T[i][l % i][getid(s[l])].update(l, -1);
      }
      s[l] = t[0];
    } else {
      int l, r;
      char t[10];
      scanf("%d%d%s", &l, &r, t);
      int len2 = strlen(t);
      int ans = 0;
      for (int i = 0; i < len2; i++) {
        ans += T[len2][(l + i) % len2][getid(t[i])].get(l, r);
      }
      printf("%d\n", ans);
    }
  }
}
