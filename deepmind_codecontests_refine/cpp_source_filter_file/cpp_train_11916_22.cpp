#include <bits/stdc++.h>
using namespace std;
long long pow17 = 100000000000000000;
long long n, pos;
int main() {
  scanf("%I64d", &n);
  for (int i = 1; i <= 810; i++) pos = (pos + pow17) % n;
  pos = n - pos;
  printf("%I64d %I64d\n", pos + 1, pos + pow17 * 10);
  return 0;
}
