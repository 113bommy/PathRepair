#include <bits/stdc++.h>
using namespace std;
int n;
long long t;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &t);
    long long sum;
    if (t % 2 != 0)
      sum = (t + 1) * (t / 2) + t / 2 + 1;
    else
      sum = (t + 1) * (t / 2);
    for (int j = 1; j <= t; j *= 2) sum -= j * 2;
    printf("%lld\n", sum);
  }
  return 0;
}
