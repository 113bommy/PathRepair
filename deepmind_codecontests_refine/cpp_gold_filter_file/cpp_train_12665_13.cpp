#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
string s[N];
int main() {
  int n, t, x, y;
  long long maxx;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; i++) cin >> s[i];
  maxx = x = y = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (s[i][j] == '.') {
        long long sum = 0;
        for (int k = i - t + 1; k <= i; k++) {
          if (k >= 0 && k + t - 1 < n) {
            long long tot = 0;
            for (int m = k; m <= k + t - 1; m++)
              if (s[m][j] == '.') tot++;
            if (tot == t) sum++;
          }
        }
        for (int k = j - t + 1; k <= j; k++) {
          if (k >= 0 && k + t - 1 < n) {
            long long tot = 0;
            for (int m = k; m <= k + t - 1; m++)
              if (s[i][m] == '.') tot++;
            if (tot == t) sum++;
          }
        }
        if (sum >= maxx) {
          maxx = sum;
          x = i;
          y = j;
        }
      }
  printf("%d %d\n", x + 1, y + 1);
  return 0;
}
