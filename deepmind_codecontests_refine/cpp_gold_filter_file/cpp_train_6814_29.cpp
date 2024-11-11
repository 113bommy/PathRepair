#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a;
  scanf("%lld", &a);
  long long tmp = (1000000000000000000 % a * 9 % a * 9 % a + 1) % a;
  long long l = a - tmp + 1;
  long long r = 1e18 + a - tmp;
  printf("%lld %lld", l, r);
}
