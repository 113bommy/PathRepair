#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int a[N];
int b[N];
int count(int x, int arr[]) {
  int cnt = upper_bound(arr + 1, arr + n + 1, x) -
            lower_bound(arr + 1, arr + n + 1, x);
  return cnt;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    int cnta = count(a[1], a);
    int cntb = count(b[i], b);
    if (cnta == cntb) {
      bool ok = 1;
      int x = b[i] - a[1] % m;
      for (int j = 2; j <= n; j++) {
        if (count(a[j], a) != count((a[j] + x) % m, b)) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        ans = min(ans, x);
      }
    }
  }
  cout << ans;
}
