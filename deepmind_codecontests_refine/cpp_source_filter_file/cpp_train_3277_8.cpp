#include <bits/stdc++.h>
using namespace std;
const int arrmax = 10;
char str[arrmax];
int reversetimes[arrmax / 2];
int main() {
  int m, a, sum, len;
  while (~scanf("%s %d", str, &m)) {
    len = strlen(str);
    memset(reversetimes, 0, 2 * len);
    while (m--) {
      scanf("%d", &a);
      reversetimes[a - 1]++;
    }
    sum = 0;
    for (int i = 0; i < len / 2; i++) {
      sum += reversetimes[i];
      if (sum & 1) swap(str[i], str[len - i - 1]);
    }
    printf("%s\n", str);
  }
  return 0;
}
