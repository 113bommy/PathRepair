#include <bits/stdc++.h>
using namespace std;
int n;
int f[100010];
int main() {
  int x;
  cin >> n;
  for (int i = 0; i <= n - 1; i++) {
    cin >> x;
    f[x]++;
  }
  for (int i = 100000; i >= 0; i--) {
    if (f[i] & 1) {
      printf("Canon\n");
      return 0;
    }
  }
  printf("Agasa\n");
  return 0;
}
