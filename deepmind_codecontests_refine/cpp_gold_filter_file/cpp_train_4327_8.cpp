#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
bool check(int arr[], int n) {
  if (arr[0] >= n && arr[1] >= n && arr[2] >= n) {
    return false;
  }
  return true;
}
int main() {
  int n, k, ans, a[5];
  scanf("%d", &n);
  scanf("%d", &k);
  a[0] = k;
  a[1] = a[0];
  a[2] = a[1];
  ans = 0;
  while (check(a, n)) {
    ans++;
    sort(a, a + 3);
    a[0] = a[1] + a[2] - 1;
  }
  printf("%d\n", ans);
  return 0;
}
