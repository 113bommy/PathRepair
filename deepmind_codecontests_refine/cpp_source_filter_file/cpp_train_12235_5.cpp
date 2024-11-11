#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  unsigned long long int a = 1;
  for (int i = 0; i < n - 3; i++) {
    a *= 4;
  }
  printf("%llu\n", ((n - 3) * 36 + 24) * a);
}
