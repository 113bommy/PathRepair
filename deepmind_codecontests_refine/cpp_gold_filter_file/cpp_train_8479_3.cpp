#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 1;
const double eps = 1e-6;
int a[103040];
int main() {
  int n, k, flag = 2, s = 1;
  cin >> n >> k;
  a[1] = 1;
  while (k) {
    a[flag] = a[flag - 1] + s * k;
    s = -s;
    k--;
    flag++;
  }
  for (int i = flag; i < n + 1; i++) {
    a[i] = i;
  }
  for (int i = 1; i < n + 1; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
