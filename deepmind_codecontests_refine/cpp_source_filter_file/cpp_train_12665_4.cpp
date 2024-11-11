#include <bits/stdc++.h>
using namespace std;
struct data {
  int i, j, val;
};
int main() {
  data mx = {1, 1, 0};
  int n, k, last, i, j, a, b, c, x, y;
  scanf("%d %d", &n, &k);
  char ara[n][n];
  int ans[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      ans[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    scanf("%s", ara[i]);
  }
  for (i = 0; i < n; i++) {
    last = -1;
    for (j = 0; j < n; j++) {
      if (ara[i][j] == '#') {
        for (a = last + 1; j - a >= k; a++) {
          for (b = a, c = 0; c < k; c++, b++) {
            ans[i][b]++;
          }
        }
        last = j;
      }
    }
    for (a = last + 1; n - a >= k; a++) {
      for (b = a, c = 0; c < k; c++, b++) {
        ans[i][b]++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    last = -1;
    for (j = 0; j < n; j++) {
      if (ara[j][i] == '#') {
        for (a = last + 1; j - a >= k; a++) {
          for (b = a, c = 0; c < k; c++, b++) {
            ans[b][i]++;
          }
        }
        last = j;
      }
    }
    for (a = last + 1; n - a >= k; a++) {
      for (b = a, c = 0; c < k; c++, b++) {
        ans[b][i]++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (ans[i][j] > mx.val) {
        mx = {i, j, ans[i][j]};
      }
    }
  }
  printf("%d %d\n", mx.i + 1, mx.j + 1);
  return 0;
}
