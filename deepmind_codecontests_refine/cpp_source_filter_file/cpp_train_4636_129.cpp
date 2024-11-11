#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  scanf("%I64d", &n);
  printf("%d\n", 2 - n & 1);
  return 0;
}
