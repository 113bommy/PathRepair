#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1111];
int main() {
  memset(a, 63, sizeof(a));
  cin >> n >> m >> k;
  for (int(i) = 0; (i) < (m); ++(i)) {
    int p, q;
    cin >> p >> q;
    --p;
    a[p] = min(a[p], q);
  }
  int sum = 0;
  for (int(i) = 0; (i) < (m); ++(i)) sum += a[i];
  cout << min(sum, k) << endl;
}
