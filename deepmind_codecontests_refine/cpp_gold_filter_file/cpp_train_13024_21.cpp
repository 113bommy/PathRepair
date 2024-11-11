#include <bits/stdc++.h>
using namespace std;
const int Maxn = 10000;
long long n, s;
int main() {
  scanf("%I64d%I64d", &n, &s);
  if (s % n)
    printf("%I64d\n", s / n + 1);
  else {
    printf("%I64d\n", s / n);
  }
  return 0;
}
