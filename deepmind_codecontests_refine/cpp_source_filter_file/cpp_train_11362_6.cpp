#include <bits/stdc++.h>
using namespace std;
int t, n, h[1000005], cnt, d[1000005], tot;
char s[1000005];
struct Edge {
  int to, next;
} w[2000005];
void add(int x, int y) {
  w[++cnt] = (Edge){y, h[x]};
  h[x] = cnt;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    tot = n;
    for (int i = 1; i <= n; i++) h[i] = 0, d[i] = 0;
    cnt = 0;
    for (int i = 1; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      add(x, y), add(y, x);
      d[x]++, d[y]++;
    }
    scanf("%s", s + 1);
    if (n < 3) {
      puts("Draw");
      continue;
    } else if (n == 3) {
      int sums = 0;
      for (int i = 1; i <= n; i++) sums += (s[i] == 'W');
      if (sums >= 2)
        puts("White");
      else
        puts("Draw");
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'W') {
        h[tot + 1] = 0;
        add(i, ++tot);
        add(tot, i);
        d[i]++, d[tot] = 3;
      }
    }
    bool flag = 0;
    int num = 0;
    for (int i = 1; i <= tot; i++) {
      if (d[i] >= 4) {
        puts("White");
        flag = 1;
        break;
      } else if (d[i] == 3) {
        int sum = 0;
        for (int i = h[i]; i; i = w[i].next) {
          int to = w[i].to;
          sum += (d[to] > 1);
        }
        if (sum >= 2) {
          puts("White");
          flag = 1;
          break;
        } else
          num++;
      }
    }
    if (flag) continue;
    if (num == 2 && tot % 2 == 1) {
      puts("White");
      continue;
    }
    puts("Draw");
  }
}
