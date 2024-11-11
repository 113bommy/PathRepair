#include <bits/stdc++.h>
using namespace std;
char* ssg = new char[3];
long long i, j, k, l, m, n;
int main() {
  int kkk = 0;
  if (kkk == 0) {
  } else {
    freopen("input.txt", "r", stdin);
  }
  scanf("%ld", &n);
  long long r[10000], a[10];
  for (long i = 0; i < n; i++) scanf("%I64d", &r[i]);
  for (long i = 0; i < 5; i++) scanf("%I64d", &a[i]);
  long long sum = 0, b[10];
  memset(b, 0, sizeof(b));
  for (long i = 0; i < n; i++) {
    sum += r[i];
    while (1) {
      long mxi = 0;
      for (long i = 0; i < 5; i++)
        if (a[i] <= sum && (a[i] > a[mxi] || a[mxi] > sum)) {
          mxi = i;
        }
      if (a[mxi] <= sum) {
        b[mxi] += sum / a[mxi];
        sum -= a[mxi] * (sum / a[mxi]);
      } else {
        break;
      }
    }
  }
  for (long i = 0; i < 5; i++) printf("%I64d ", b[i]);
  printf("\n%I64d", sum);
  return 0;
}
