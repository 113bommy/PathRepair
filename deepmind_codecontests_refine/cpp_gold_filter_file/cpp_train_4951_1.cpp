#include <bits/stdc++.h>
using namespace std;
int n;
bool f[50][50];
void print() {
  int odd = 1, even = 2, curr = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (f[i][j]) {
        curr = odd;
        odd += 2;
      } else {
        curr = even;
        even += 2;
      }
      printf("%d ", curr);
    }
    printf("\n");
  }
}
int main() {
  scanf("%d", &n);
  int x = n / 2, cnt = (n * n - 1) / 2;
  f[x][x] = true;
  int i = 0;
  assert(cnt % 4 == 0);
  while (cnt > 0 && i < x) {
    f[i][x] = f[n - 1 - i][x] = f[x][i] = f[x][n - 1 - i] = true;
    cnt -= 4;
    i++;
  }
  if (cnt == 0) {
    print();
    return 0;
  }
  assert(cnt > 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!f[i][j]) {
        f[i][j] = f[n - 1 - i][j] = f[i][n - 1 - j] = f[n - 1 - i][n - 1 - j] =
            true;
        cnt -= 4;
        if (cnt == 0) {
          print();
          return 0;
        }
        assert(cnt > 0);
      }
  return 0;
}
