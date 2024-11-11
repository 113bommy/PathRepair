#include <bits/stdc++.h>
using namespace std;
int grundy[100001];
void calcgrundy(int n) {
  vector<bool> marked(100001, false);
  for (int k = 2; 2 * n - k * k + k > 0; ++k) {
    if ((2 * n - k * k + k) % (2 * k) != 0) continue;
    int a0 = (2 * n - k * k + k) / (2 * k);
    marked[grundy[a0 + k - 1] ^ grundy[a0 - 1]] = true;
  }
  for (int i = 0; i < 100001; ++i)
    if (!marked[i]) {
      grundy[n] = i ^ grundy[n - 1];
      break;
    }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) calcgrundy(i);
  if ((grundy[n] ^ grundy[n - 1]) == 0) {
    printf("-1");
    return 0;
  }
  for (int k = 2; 2 * n - k * k + k > 0; ++k) {
    if ((2 * n - k * k + k) % (2 * k) != 0) continue;
    int a0 = (2 * n - k * k + k) / (2 * k);
    if ((grundy[a0 + k - 1] ^ grundy[a0 - 1]) == 0) {
      printf("%d %d", k, a0);
      return 0;
    }
  }
}
