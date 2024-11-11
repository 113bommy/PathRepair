#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, i, j, r;
  unsigned long long p = 0, q;
  cin >> k;
  n = log2(k) / 2;
  n++;
  int a[k];
  for (i = 0; i < k; i++) scanf("%d", a[i]);
  sort(a, a + k, greater<int>());
  r = 0;
  for (i = 1; i <= k; i = 4 * i) {
    for (j = 0; j < i; j++) p = p + a[j];
  }
  cout << p;
  return 0;
}
