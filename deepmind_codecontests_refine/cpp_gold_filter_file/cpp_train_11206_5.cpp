#include <bits/stdc++.h>
using namespace std;
long long n, k;
int a[100005];
int main() {
  scanf("%I64d%I64d", &n, &k);
  int i;
  for (i = 1; i <= (k < 100000 ? k : 100000); i++) {
    a[n % i]++;
    if (a[n % i] >= 2) return !printf("No");
  }
  return !printf("Yes");
}
