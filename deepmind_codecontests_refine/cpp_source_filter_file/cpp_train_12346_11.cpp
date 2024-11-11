#include <bits/stdc++.h>
using namespace std;
void update(int *arr, int pos, int diff) {
  while (pos <= 100001) {
    arr[pos] = max(arr[pos], diff);
    pos += pos & -pos;
  }
}
int sum(int *arr, int pos) {
  int ret = 0;
  while (pos > 0) {
    ret = max(ret, arr[pos]);
    pos -= pos & -pos;
  }
  return ret;
}
int n, c, d;
int coin[100001], dia[100001];
int main() {
  scanf("%d%d%d", &n, &c, &d);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int b, p;
    char k;
    int coin_max, dia_max, m;
    coin_max = 0;
    dia_max = 0;
    scanf("%d%d %c", &b, &p, &k);
    if (k == 'C') {
      coin_max = sum(dia, d);
      if (p > c) continue;
      coin_max = max(coin_max, sum(coin, c - p));
      update(coin, p, b);
    } else {
      dia_max = sum(coin, c);
      if (p > d) continue;
      dia_max = max(dia_max, sum(dia, d - p));
      update(coin, p, b);
    }
    if (coin_max == 0 && dia_max == 0) continue;
    m = max(b + coin_max, b + dia_max);
    ans = max(ans, m);
  }
  printf("%d\n", ans);
  return 0;
}
