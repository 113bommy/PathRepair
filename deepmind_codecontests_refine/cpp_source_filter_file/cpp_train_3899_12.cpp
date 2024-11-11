#include <bits/stdc++.h>
using namespace std;
int const N = 3e3 + 5, M = 12 + 5, OO = 0x3f3f3f3f, MOD = 131071;
int n, v, a, b, mx, t, ans, x, temp;
int arr[N];
int main() {
  scanf("%d %d", &n, &v);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    arr[a] = b;
    mx = max(mx, a);
  }
  mx++;
  for (int i = 1; i <= mx; i++) {
    temp = min(v, x);
    if (temp < v) {
      t = min(v - temp, arr[i]);
      arr[i] -= t;
      temp += t;
    }
    x = arr[i];
    ans += temp;
  }
  printf("%d\n", ans);
  return 0;
}
