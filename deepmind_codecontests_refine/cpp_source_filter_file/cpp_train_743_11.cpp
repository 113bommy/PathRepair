#include <bits/stdc++.h>
using namespace std;
const int maxn = 255;
int n, k, m, t, pos, len;
int ans1[maxn], ans2[maxn];
int main() {
  scanf("%d%d%d%d", &n, &k, &m, &t);
  pos = k;
  len = n;
  for (int i = 1; i <= t; i++) {
    int op, num;
    scanf("%d%d", &op, &num);
    if (op == 0) {
      if (num < pos) {
        pos -= num;
        len -= num;
      } else
        len -= (len - num);
    } else {
      if (num <= pos) {
        pos++;
        len++;
      } else
        len++;
    }
    ans1[i] = len;
    ans2[i] = pos;
  }
  for (int i = 1; i <= t; i++) printf("%d %d\n", ans1[i], ans2[i]);
  return 0;
}
