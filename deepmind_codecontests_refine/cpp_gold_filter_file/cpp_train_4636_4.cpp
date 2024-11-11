#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  scanf("%I64d", &n);
  printf("%d\n", 2 - int(n & 1ll));
  return 0;
}
