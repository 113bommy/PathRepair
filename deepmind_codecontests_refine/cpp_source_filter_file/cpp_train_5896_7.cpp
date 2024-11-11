#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans, i, a[200009], b[200009];
  scanf("%d", &n);
  ans = 1;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    if (!b[a[i]])
      b[a[i]] = 1;
    else
      ans++;
  }
  cout << ans << endl;
}
