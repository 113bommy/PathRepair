#include <bits/stdc++.h>
using namespace std;
int prime[70000];
void ptable() {
  memset(prime, 1, sizeof(prime));
  for (int i = 2; i * i < 70000; i++) {
    if (prime[i]) {
      for (int j = i * 2; j < 70000; j += i) {
        prime[j] = 0;
      }
    }
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  printf("%d\n", (6 * n - 1) * k);
  for (int i = 0; i < n; i++) {
    printf("%d %d %d %d\n", (6 * i + 1) * k, (6 * i + 2) * k, (6 * i + 3) * k,
           (6 * i + 5) * k);
  }
  return 0;
}
