#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
const double PI = acos(-1.0);
const double EPS = 1e-6;
int used[N];
int main() {
  int n;
  scanf("%d", &n);
  memset(used, -1, sizeof(used));
  for (int j = 1; j <= n; j++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int count = 0;
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        if (used[i] < j - y) {
          count++;
        }
        used[i] = j;
        if (i * i != x && used[x / i] == -1) {
          count++;
        }
        used[x / i] = j;
      }
    }
    printf("%d\n", count);
  }
  return 0;
}
