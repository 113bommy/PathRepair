#include <bits/stdc++.h>
int n, k;
int data[100];
using namespace std;
void read() {
  int i;
  for (i = 1; i <= n; ++i) {
    scanf("%d%*c", &data[i]);
  }
  sort(&data[1], &data[1] + n);
}
int main() {
  while (scanf("%d%*c%d%*c", &n, &k) != EOF) {
    read();
    int p = n - k + 1;
    if (p < 1) {
      printf("-1\n");
    } else {
      printf("%d %d\n", data[p], data[p]);
    }
  }
  return 0;
}
