#include <bits/stdc++.h>
using namespace std;
int a[1050];
map<int, int> mp;
int main() {
  int n, t, mx = 1;
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      mx = max(mx, a[i]);
    }
    sort(a, a + n);
    int f = 0, in = 0;
    for (int j = 1; j <= 1024; j++) {
      mp.clear();
      f = 0;
      for (int i = 0; i < n; i++) {
        int p = a[i] ^ j;
        mp[p] = 1;
      }
      for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 0) {
          f = 1;
          break;
        }
      }
      if (f == 0) {
        in = j;
        break;
      }
    }
    if (f == 0)
      printf("%d\n", in);
    else
      printf("-1\n");
  }
}
