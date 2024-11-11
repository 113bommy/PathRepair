#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
long long a[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int ans = 0, it = 0;
  while (it < n) {
    ans++;
    int pr = 0, suf = 0, val = 0;
    while (it < n && a[it] == -1) pr++, it++;
    if (it == n) break;
    val = a[it];
    it++;
    while (it < n && a[it] == -1) suf++, it++;
    if (it == n) break;
    int val1 = a[it];
    if ((val1 - val) % (suf + 1) != 0) continue;
    long long d = (val1 - val) / (suf + 1);
    if ((long long)val - pr * d <= 0) continue;
    it++;
    while (it < n)
      if (a[it] == -1) {
        if (a[it - 1] + d <= 0) break;
        a[it] = a[it - 1] + d;
        it++;
      } else {
        if (a[it] != a[it - 1] + d) break;
        it++;
      }
  }
  printf("%d\n", ans);
  return 0;
}
