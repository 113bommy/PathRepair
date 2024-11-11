#include <bits/stdc++.h>
using namespace std;
int main() {
  puts("1998");
  int n = 2000;
  for (int i = 2; i <= n; i++) printf("%d %d %d %d\n", i, 1, i, 2);
  for (int i = n; i >= 2; i--) printf("%d %d %d %d\n", i, 1, i, 2);
  return 0;
}
