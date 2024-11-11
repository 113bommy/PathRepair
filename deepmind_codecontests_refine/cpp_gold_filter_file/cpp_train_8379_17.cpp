#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
int main() {
  scanf("%d", &n);
  int a = 1, b = 1;
  for (int i = 0; i < n; i++) {
    a = a * 27ll % mod;
    b = b * 7ll % mod;
  }
  a = (a - b + mod) % mod;
  printf("%d\n", a);
  return 0;
}
