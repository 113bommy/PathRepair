#include <bits/stdc++.h>
const int SIZE = 4e5 + 50;
int cnt[SIZE];
int main() {
  int q, x;
  scanf("%d%d", &q, &x);
  int pos = 0;
  while (q--) {
    int y;
    scanf("%d", &y);
    y %= x;
    cnt[y]++;
    while (cnt[pos % x]) {
      cnt[pos % x]--;
      pos++;
    }
    printf("%d\n", pos);
  }
}
