#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, sum = 0, n, k;
  cin >> n;
  cin >> k;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n; i += k) {
    sum += (a[i] - 1) * 2;
  }
  printf("%d", sum);
}
