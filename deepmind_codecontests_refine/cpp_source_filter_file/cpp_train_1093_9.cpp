#include <bits/stdc++.h>
using namespace std;
long long int x, y;
void binn(long long int a[], long long int n, long long int k) {
  long long int i, j;
  i = 1;
  j = n;
  while (i <= j) {
    long long int mid = (i + j) / 2;
    if (a[mid] < k) {
      i = mid + 1;
    } else {
      x = mid;
      y = k - a[mid - 1];
      j = mid - 1;
    }
  }
}
int main() {
  long long int n, k, i, j, l;
  cin >> n >> k;
  long long int a[n + 2];
  for (i = 1; i <= n; i++) cin >> a[i];
  j = n;
  long long int maxx = 0;
  while (j < (2 * k)) {
    if (a[j] > maxx) maxx = a[j];
    j -= 1;
    k -= 1;
  }
  for (i = 1; i <= j; i++) {
    l = a[i] + a[j + 1 - i];
    if (l > maxx) maxx = l;
  }
  cout << maxx << endl;
  return 0;
}
