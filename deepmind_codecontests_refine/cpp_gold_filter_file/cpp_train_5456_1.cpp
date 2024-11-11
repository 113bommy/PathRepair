#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  n = n * 2;
  int na = 0, nb = 0;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    char b, c, d;
    scanf("%d.%c%c%c", &a, &b, &c, &d);
    if (b == '0' && c == '0' && d == '0') {
      ++nb;
    } else {
      ++na;
      sum += (b - '0') * 100 + (c - '0') * 10 + (d - '0');
    }
  }
  int high, low;
  if (nb >= na) {
    high = n * 1000;
    low = 0;
  } else {
    high = ((na - nb) / 2 + nb) * 1000;
    low = (na - nb) / 2 * 1000;
  }
  if (sum >= high)
    printf("%d.%03d\n", (sum - high) / 1000, sum % 1000);
  else if (sum <= low)
    printf("%d.%03d\n", (low - sum) / 1000, (low - sum) % 1000);
  else {
    int ans = (sum % 1000 > 500 ? 1000 - sum % 1000 : sum % 1000);
    printf("0.%03d\n", ans);
  }
  return 0;
}
