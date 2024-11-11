#include <bits/stdc++.h>
using namespace std;
const long long int Mod = 1e9 + 7, MX = 1e7, MN = LLONG_MIN;
void Print(long long int a, long long int b = MN, long long int c = MN,
           long long int d = MN) {
  printf("%lld", a);
  if (b != MN) printf(" %lld", b);
  if (c != MN) printf(" %lld", c);
  if (d != MN) printf(" %lld", d);
  puts("");
}
int main() {
  long long int n, m, cs = 1;
  scanf("%*d");
  while (cin >> n) {
    printf("1 %lld\n", n - 1);
  }
  return 0;
}
