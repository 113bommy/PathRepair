#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%lld", &n);
  long long t;
  t = n * (n - 1) / 2;
  if (t % 2 == 0)
    printf("0\n");
  else
    printf("1\n");
  return 0;
}
