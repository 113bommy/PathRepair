#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, sum = 0, dao;
  scanf("%lld", &n);
  long long m[n + 5];
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &m[i]);
  }
  for (long long i = n; i > 0; i--) {
    if (i == n) {
      sum++;
      dao = m[i];
      continue;
    }
    dao--;
    if (dao < 0) {
      sum++;
      dao = 0;
    }
    if (m[i] > dao) {
      dao += m[i];
    }
  }
  printf("%d", sum);
  return 0;
}
