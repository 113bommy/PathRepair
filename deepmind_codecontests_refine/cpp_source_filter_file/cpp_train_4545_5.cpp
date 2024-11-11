#include <bits/stdc++.h>
using namespace std;
char a[5005];
bool dp[5005][4105];
struct letter {
  char x;
  int id;
  friend bool operator<(const letter &a, const letter &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.id < b.id;
  }
};
letter b[5005];
int main() {
  scanf("%s", a);
  int k;
  int n = strlen(a);
  for (k = 1; (1 << k) < n; k++)
    ;
  int i, j;
  for (i = 0; i < n; i++) {
    b[i].x = a[i];
    b[i].id = i;
  }
  sort(b, b + n);
  k--;
  int t = n - (1 << k) + 1;
  dp[0][0] = true;
  for (i = 0; i < t; i++) {
    for (j = i; j < n; j++) {
      if (j - i >= ((1 << k) - 1)) continue;
      if (dp[j][j - i]) {
        int l;
        for (l = 0; l < k; l++) {
          if ((1 << l) & (j - i)) continue;
          dp[i + ((j - i) ^ (1 << l))][(j - i) ^ (1 << l)] = true;
        }
      }
    }
    char next_max = 'z';
    for (j = i; j < n; j++) {
      if (j - i >= ((1 << k) - 1)) continue;
      if (dp[j][j - i]) {
        next_max = min(next_max, a[j]);
      }
    }
    putchar(next_max);
    for (j = i; j < n; j++) {
      if (j - i >= ((1 << k) - 1)) continue;
      if ((dp[j][j - i]) && (a[j] == next_max)) {
        dp[j + 1][j - i] = true;
      }
    }
  }
  return 0;
}
