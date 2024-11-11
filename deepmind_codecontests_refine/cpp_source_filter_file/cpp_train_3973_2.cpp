#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
bool a[maxn];
int main() {
  int n, k;
  while (~scanf("%d%d", &n, &k)) {
    int p = (n - k) / 2 + 1;
    int t = n / p;
    while (t--) {
      for (int i = 0; i < p; i++) {
        if (i == p - 1)
          printf("0");
        else
          printf("1");
      }
    }
    for (int i = 0; i < n % p; i++) printf("0");
    printf("\n");
  }
}
