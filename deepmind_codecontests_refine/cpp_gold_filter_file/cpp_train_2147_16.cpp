#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
long long n;
long long k1, k2, k3;
long long t1, t2, t3;
long long ar[MAXN];
long long fi[MAXN];
int main() {
  cin >> k1 >> k2 >> k3;
  cin >> t1 >> t2 >> t3;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    fi[i] = ar[i];
  }
  sort(ar + 1, ar + n + 1);
  long long i, j;
  for (i = k1 + 1, j = 1; i <= n; i++, j++) {
    ar[j] += t1;
    ar[i] = max(ar[i], ar[j]);
  }
  for (; j <= n; j++) ar[j] += t1;
  for (i = k2 + 1, j = 1; i <= n; i++, j++) {
    ar[j] += t2;
    ar[i] = max(ar[i], ar[j]);
  }
  for (; j <= n; j++) ar[j] += t2;
  for (i = k3 + 1, j = 1; i <= n; j++, i++) {
    ar[j] += t3;
    ar[i] = max(ar[i], ar[j]);
  }
  for (; j <= n; j++) ar[j] += t3;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, ar[i] - fi[i]);
  }
  cout << res << endl;
  return 0;
}
