#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000008;
const double eps = 1e-6;
int main() {
  long long n, p;
  char str[100][100];
  while (cin >> n >> p) {
    long long sum = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
      if (strcmp(str[i], "halfplus") == 0) x++;
    }
    long long now = 1;
    for (int i = n - 2; i >= 0; i--) {
      if (strcmp(str[i], "halfplus") == 0)
        now = now * 2 + 1;
      else {
        now = now * 2;
      }
    }
    printf("%.0lf\n", now * p - x * (p / 2.0));
  }
}
