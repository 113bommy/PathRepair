#include <bits/stdc++.h>
using namespace std;
int k, b, n;
int a[100100];
int c[100100];
map<int, int> sum;
int main() {
  scanf("%d%d%d", &k, &b, &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  long long ans = 0;
  int s = 0;
  sum[0]++;
  if (b)
    for (int i = 0; i < n; i++) {
      s += a[i];
      s %= (k - 1);
      int tmp = (s - b + k - 1) % (k - 1);
      ans += sum[tmp];
      sum[s]++;
    }
  long long ans2 = 0;
  for (int i = 0; i < n; i++)
    if (!a[i]) {
      int j = i;
      for (; j < n && !a[j]; j++)
        ;
      long long cnt = j - i;
      ans2 += (1 + cnt) * cnt / 2;
      i = j;
    }
  if (b == k - 1) ans -= ans2;
  if (!b) ans = ans2;
  ans = max(ans, 0ll);
  cout << ans << endl;
  return 0;
}
