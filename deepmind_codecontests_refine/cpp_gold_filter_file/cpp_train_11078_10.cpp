#include <bits/stdc++.h>
using namespace std;
int str[2000000];
bool can[2000000];
int main() {
  int i, j, k;
  int n, m, d;
  int now;
  while (cin >> n >> d) {
    for (i = 1; i <= n; i++) {
      scanf("%d", &str[i]);
    }
    sort(str + 1, str + 1 + n);
    now = 0;
    memset(can, false, sizeof(can));
    can[0] = true;
    for (i = 1; i <= n; i++) {
      for (j = 2000000 - 1; j >= str[i]; j--) {
        if (can[j - str[i]]) can[j] = true;
      }
    }
    int day = 0;
    int now = 0;
    while (1) {
      for (i = now + d; i > now; i--) {
        if (can[i]) break;
      }
      if (i == now) break;
      day++;
      now = i;
    }
    printf("%d %d\n", now, day);
  }
  return 0;
}
