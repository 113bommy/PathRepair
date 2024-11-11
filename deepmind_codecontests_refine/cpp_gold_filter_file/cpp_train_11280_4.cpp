#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 20;
int a[maxn];
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) a[i] = 1;
  int k1 = n + 1;
  int k2 = k;
  while (k1 <= m + n) {
    k2++;
    a[k2] = k1 - 1;
    for (int i = 1; i < k; i++) {
      k2++;
      a[k2] = k1;
    }
    if (k == 1) k1--;
    k1 += n;
  }
  if (n + m + 1 == k1) a[++k2] = n + m;
  cout << k2 << endl;
  for (int i = 1; i <= k2; i++) cout << a[i] << " ";
  return 0;
}
