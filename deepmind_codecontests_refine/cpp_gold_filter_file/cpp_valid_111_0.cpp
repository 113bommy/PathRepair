#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= i; j++) printf("(");
      for (long long j = 1; j <= i; j++) printf(")");
      for (long long j = i + 1; j <= n; j++) printf("(");
      for (long long j = i + 1; j <= n; j++) printf(")");
      printf("\n");
    }
  }
  return 0;
}
