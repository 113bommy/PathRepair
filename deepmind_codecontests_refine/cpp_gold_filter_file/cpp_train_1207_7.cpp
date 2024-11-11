#include <bits/stdc++.h>
using namespace std;
int compare(const void *a, const void *b) {
  return (*((int *)b) - *((int *)a));
}
int maxx(int a, int b) { return (a < b) ? b : a; }
int main() {
  unsigned long int n, k = 0;
  unsigned long long ans = 0;
  unsigned long long int a[1010];
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  qsort(a, n, sizeof(unsigned long long int), compare);
  for (int i = n - 1; i > -1; i--) {
    if (a[i] <= k * 2) {
      if (k < a[i]) k = a[i];
    } else {
      ans++;
      k *= 2;
      i++;
    }
  }
  cout << ans;
  return 0;
}
