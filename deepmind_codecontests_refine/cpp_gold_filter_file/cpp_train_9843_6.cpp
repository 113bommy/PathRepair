#include <bits/stdc++.h>
using namespace std;
int n, T, cnt, top;
char s[5100][5100];
struct poi {
  int x, y;
  poi() {}
  poi(int x, int y) : x(x), y(y) {}
  void trs() {
    swap(x, y);
    x--;
    y = n - y;
  }
  friend bool operator<(const poi &r1, const poi &r2) {
    if (r1.x == r2.x) return r1.y < r2.y;
    return r1.x < r2.x;
  }
  friend int operator^(const poi &r1, const poi &r2) {
    return r1.x * r2.y - r2.x * r1.y;
  };
  friend poi operator-(const poi &r1, const poi &r2) {
    return poi(r1.x - r2.x, r1.y - r2.y);
  };
} a[5100 << 5], st[5100 << 5];
int onleft(poi p1, poi p2, poi p3) { return ((p1 - p2) ^ (p3 - p2)) >= 0; }
int main() {
  while (scanf("%d", &n) != EOF && n) {
    top = 0;
    cnt = 0;
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (s[i][j] > '0' && s[i][j + 1] > '0' && s[i + 1][j] > '0' &&
            s[i + 1][j + 1] > '0' &&
            (s[i][j] == '1' || s[i][j + 1] == '1' || s[i + 1][j] == '1' ||
             s[i + 1][j + 1] == '1'))
          a[++cnt] = poi(i, j + 1);
    for (int i = 1; i <= cnt; i++) a[i].trs();
    sort(a + 1, a + 1 + cnt);
    for (int i = 1; i <= cnt; i++) {
      while (top >= 2 && onleft(st[top], st[top - 1], a[i])) top--;
      st[++top] = a[i];
    }
    int t = top;
    for (int i = cnt - 1; i >= 1; i--) {
      while (top > t && onleft(st[top], st[top - 1], a[i])) top--;
      st[++top] = a[i];
    }
    printf("%d\n", top - 1);
    for (int i = 1; i < top; i++) printf("%d %d\n", st[i].x, st[i].y);
  }
  return 0;
}
