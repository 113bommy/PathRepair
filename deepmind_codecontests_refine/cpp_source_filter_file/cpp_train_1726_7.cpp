#include <bits/stdc++.h>
using namespace ::std;
const int maxn = 50 + 5;
int n, l, a[maxn], b[maxn];
void solve() {
  scanf("%d%d", &n, &l);
  int k;
  scanf("%d", &a[0]);
  k = a[0];
  a[0] = 0;
  for (int i = 1; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] -= k;
  }
  scanf("%d", &b[0]);
  k = b[0];
  b[0] = 0;
  for (int i = 1; i < n; i++) {
    scanf("%d", &b[i]);
    b[i] -= k;
  }
  for (int i = 0; i < n; i++) {
    k = b[i];
    int flag = 1;
    for (int j = i; j < i + n; j++) {
      if (j < n && a[j - i] != b[j] - k) {
        flag = 0;
        break;
      } else if (j > n && a[j - i] != b[j - n] + n - k) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}
int main() {
  solve();
  return 0;
}
