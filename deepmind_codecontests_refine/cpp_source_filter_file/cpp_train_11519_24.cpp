#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, a[10010];
  scanf("%I64d %I64d %I64d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
  if (n % 2) {
    long long val = (1LL << 62);
    for (int i = 0; i < n; i++) {
      if (!(i % 2)) val = min(val, a[i]);
    }
    val = min(val, (k * m) / (n / 2 + 1));
    cout << val << endl;
  } else {
    cout << 0 << endl;
  }
}
