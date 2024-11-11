#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n > 36) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n / 2; ++i) printf("8");
  if (n % 2 != 0) printf("0\n");
  return 0;
}
