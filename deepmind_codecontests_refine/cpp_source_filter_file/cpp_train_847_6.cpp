#include <bits/stdc++.h>
using namespace std;
int n, m;
void print(int a) {
  printf("1 %09d\n", a);
  exit(0);
}
int main() {
  int a, b, mod;
  long long int i;
  int tar;
  scanf("%d%d%d", &a, &b, &mod);
  if (b >= mod - 1) {
    printf("2\n");
    exit(0);
  }
  tar = (int)(1e9) % mod;
  if (!tar) {
    printf("2\n");
    exit(0);
  }
  for (i = 0; i <= min(a, tar * mod); i++) {
    if (((((i % mod) * tar) % mod) ? ((i % mod) * tar) % mod : mod + 1) <
        ((mod - b) ? mod - b : mod)) {
      print(i);
    }
  }
  printf("2\n");
  return 0;
}
