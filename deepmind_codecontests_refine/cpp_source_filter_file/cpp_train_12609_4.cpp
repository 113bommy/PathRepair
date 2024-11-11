#include <bits/stdc++.h>
using namespace std;
char s[3000005], t[3000005];
int n, k;
int p[3000006], q[3000006];
int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  scanf("%s", t);
  int idx = n;
  for (int i = 0; i < n; i++)
    if (s[i] != t[i]) {
      idx = i;
      break;
    }
  if (idx == n)
    printf("%d\n", n);
  else if (k == 1)
    printf("%d\n", n);
  else {
    long long ans = 2 * n - idx;
    k -= 2;
    for (int i = idx + 1; i < n; i++) {
      if (s[i] == 'a') {
        p[n - i - 1] += 1;
        q[n - i] += 1;
      }
      if (t[i] == 'b') {
        p[n - i - 1] += 1;
        q[n - i] += 1;
      }
    }
    for (int i = n - 1; i >= 1; i--) {
      p[i - 1] += min(p[i] * 2, k);
    }
    for (int i = n - 1; i >= 1; i--) {
      p[i] = min(p[i] + q[i], k);
    }
    for (int i = n - 1; i >= 1; i--) {
      int tmp = min(p[i], k);
      k -= tmp;
      ans += tmp * i;
      if (k == 0) break;
    }
    cout << ans << endl;
  }
  return 0;
}
