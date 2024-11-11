#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int result = 0;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i = i * 10) {
    result = result + n - i + 1;
  }
  printf("%I64d\n", result);
  return 0;
}
