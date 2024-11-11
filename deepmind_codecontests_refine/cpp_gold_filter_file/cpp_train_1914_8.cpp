#include <bits/stdc++.h>
using namespace std;
bool arr[51][51];
int cnt[51];
int main() {
  int n, m;
  scanf("%d", &n);
  m = (n * (n - 1) / 2) - 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    arr[a][b] = true;
    arr[b][a] = false;
    cnt[a]++;
    cnt[b]++;
  }
  int a = 0, b = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] != n - 1) {
      if (!a)
        a = i;
      else {
        b = i;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i == a || i == b) continue;
    if (arr[a][i] && arr[i][b]) {
      printf("%d %d\n", a, b);
      return 0;
    } else if (arr[b][i] && arr[i][a]) {
      printf("%d %d\n", b, a);
      return 0;
    }
  }
  printf("%d %d\n", a, b);
  return 0;
}
