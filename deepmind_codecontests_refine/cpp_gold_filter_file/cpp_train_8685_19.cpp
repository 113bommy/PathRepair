#include <bits/stdc++.h>
using namespace std;
const int MAXINT = 0x6fffffff;
const long long MAXLONG = (long long)1 << 60;
const int MAXN = 105;
int ar1[MAXN], ar2[MAXN];
void calc(int arr[], int n) {
  if (n == 1) {
    arr[0] = 1;
    return;
  } else if (n == 2) {
    arr[0] = 3;
    arr[1] = 4;
    return;
  }
  fill(arr, arr + n, 1);
  if (n % 2 == 0) {
    arr[n - 1] = (n - 1) / 2;
  } else {
    arr[0] = 2;
    arr[n - 1] = (n + 1) / 2;
  }
}
int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != -1) {
    calc(ar1, n);
    calc(ar2, m);
    for (long long i = (0); i < (n); i += 1) {
      for (long long j = (0); j < (m); j += 1) {
        printf("%d%c", ar1[i] * ar2[j], j + 1 == m ? '\n' : ' ');
      }
    }
  }
  return 0;
}
