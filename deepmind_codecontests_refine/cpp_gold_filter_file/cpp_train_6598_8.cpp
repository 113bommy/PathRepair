#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 12;
int res[N], bit[32];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n + 1; ++i) res[i] = i;
  for (int i = 0; i <= 20; ++i) bit[i] = (((1 << i) & n) ? 1 : 0);
  bool ok = true;
  int now = 0;
  for (int i = 0; i < 22; ++i)
    if (bit[21 - i]) {
      int b = (1 << (21 - i));
      for (int j = 0; j < n - b - now + 1; ++j)
        swap(res[j + now], res[j + now + b]);
      reverse(res + now, res + now + b);
      now += b;
    }
  long long ret = 0;
  for (int i = 0; i < n + 1; ++i) ret += (res[i] ^ i);
  printf("%I64d\n", ret);
  for (int i = 0; i < n; ++i) printf("%d ", res[i]);
  printf("%d\n", res[n]);
  return 0;
}
