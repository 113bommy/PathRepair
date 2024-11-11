#include <bits/stdc++.h>
using namespace std;
long long k, p, a[100010], n;
int main() {
  cin >> p >> k;
  long long t = 0;
  for (; p; a[++n] = t) {
    t = p % k;
    p = p / (-k);
    if (t < 0) t += k, p++;
  }
  cout << n << endl;
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
