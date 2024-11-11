#include <bits/stdc++.h>
using namespace std;
int main() {
  long a[100002], k, l, m, n, d, t = 0;
  for (int i = 1; i <= d; i++) a[i] = 0;
  cin >> k;
  cin >> l;
  cin >> m;
  cin >> n;
  cin >> d;
  for (int i = 1; i <= d; i++) {
    if (i % k == 0) a[i] = 1;
    if (i % l == 0) a[i] = 1;
    if (i % m == 0) a[i] = 1;
    if (i % n == 0) a[i] = 1;
  }
  for (int i = 1; i <= d; i++)
    if (a[i] == 1) t++;
  cout << t;
  return 0;
}
