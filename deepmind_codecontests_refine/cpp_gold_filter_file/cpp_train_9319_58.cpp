#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  long long int a[n], b[n], p = 0, q = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &a[i]);
    p |= a[i];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &b[i]);
    q |= b[i];
  }
  printf("%I64d\n", p + q);
  return 0;
}
