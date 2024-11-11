#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, t;
int a[2 * N];
int main() {
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = n; i < 2 * n; ++i) a[i] = a[i - n];
  for (int i = 1; i < 2 * n; ++i) a[i] += a[i - 1];
  int nxt = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    while (nxt < n && a[nxt] - ((i > 0) ? a[i - 1] : 0) <= t) {
      ans = max(ans, nxt - i + 1);
      nxt++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
