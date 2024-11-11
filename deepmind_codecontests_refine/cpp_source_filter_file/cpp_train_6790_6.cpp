#include <bits/stdc++.h>
using namespace std;
int t;
double n, d;
int main() {
  scanf("%d", &t);
  while (t--) {
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    long long num = 9, cnt = 0;
    while (b > num) cnt++, num = num * 10 + 9;
    printf("%I64d\n", cnt * a);
  }
  return 0;
}
