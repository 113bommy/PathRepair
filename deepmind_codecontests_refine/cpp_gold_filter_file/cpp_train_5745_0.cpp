#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int inf = 1e9;
int q;
int n, m, k, input[110];
int main() {
  int i;
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &input[i]);
    }
    int flag = 0;
    for (i = 1; i < n; i++) {
      int help = max(input[i + 1] - k, 0);
      if (input[i] >= input[i + 1] - k) {
        m += (input[i] - help);
      } else {
        int t = input[i + 1] - k - input[i];
        if (t <= m)
          m -= t;
        else {
          flag = 1;
          break;
        }
      }
    }
    if (flag) {
      printf("NO\n");
    } else
      printf("YES\n");
  }
}
