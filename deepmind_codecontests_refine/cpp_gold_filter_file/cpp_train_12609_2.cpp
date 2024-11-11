#include <bits/stdc++.h>
using namespace std;
const int N = 510000;
int n, k;
char s1[N], s2[N];
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s%s", s1 + 1, s2 + 1);
  long long ans = 0, now = 0, last = 0;
  for (int i = 1; i <= n; i++) {
    now = (now << 1) + s2[i] - s1[i];
    long long tmp = min((long long)k, now + 1) - last;
    ans += tmp * (n - i + 1);
    last += tmp;
    if (last == k) break;
  }
  cout << ans << endl;
  return 0;
}
