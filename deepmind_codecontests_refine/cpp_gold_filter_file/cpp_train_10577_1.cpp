#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
map<char, int> ma;
char s[N];
int n;
int c[5][11][11][N];
int lowbit(int x) { return x & (-x); }
void add(int ty, int pos, int x) {
  for (int i = pos; i < N; i += lowbit(i)) {
    for (int j = 1; j <= 10; j++) {
      c[ty][j][pos % j][i] += x;
    }
  }
}
int ask(int x, int ty, int len, int pos) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i)) ans += c[ty][len][pos][i];
  return ans;
}
int query(int l, int r, int ty, int len, int pos) {
  return ask(r, ty, len, pos) - ask(l - 1, ty, len, pos);
}
char str[N];
int main() {
  ma['A'] = 1;
  ma['T'] = 2;
  ma['G'] = 3;
  ma['C'] = 4;
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  for (int i = 1; i <= len; i++) add(ma[s[i]], i, 1);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x;
      scanf("%d%s", &x, str);
      add(ma[s[x]], x, -1);
      s[x] = str[0];
      add(ma[s[x]], x, 1);
    } else {
      int l, r;
      scanf("%d%d%s", &l, &r, str);
      int len = strlen(str);
      int ans = 0;
      for (int j = 0; j < len; j++)
        ans += query(l, r, ma[str[j]], len, (l + j) % len);
      printf("%d\n", ans);
    }
  }
}
