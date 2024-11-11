#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int a[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) a[i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = i + i; j <= n; j += i) {
      a[j] = i;
    }
  }
  sort(a + 2, a + 1 + n);
  for (int i = 2; i <= n; i++) printf("%d%c", a[i], i == n ? '\n' : ' ');
  return 0;
}
