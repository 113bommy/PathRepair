#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn = 2e5 + 300;
int a[maxn], b[maxn];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  sort(a, a + n);
  for (int i = 0; i < m; i++) {
    int p = lower_bound(a, a + n, b[i]) - a;
    printf("%d ", p);
  }
  return 0;
}
