#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int n;
  string s;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = 1, r = n;
  int t = 0, ans = 0;
  while (l <= r) {
    int u = a[l] > t;
    int v = a[r] > t;
    if (u && v) {
      if (a[l] - t < a[r] - t) {
        ans++;
        s += 'L';
        t = a[l++];
      } else {
        ans++;
        s += 'R';
        t = a[r--];
      }
    } else if (u || v) {
      if (u) {
        ans++;
        s += 'L';
        t = a[l++];
      } else if (v) {
        ans++;
        s += 'R';
        t = a[r--];
      }
    } else
      break;
  }
  printf("%d\n", ans);
  cout << s;
}
