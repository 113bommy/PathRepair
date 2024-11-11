#include <bits/stdc++.h>
using namespace std;
int n, m, mmax, a[1000001], cnt[1000001], ans;
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= n; i++) {
    if (a[i] != m) {
      if (cnt[a[i]] >= cnt[m]) cnt[a[i]]++;
    } else {
      cnt[m]++;
    }
  }
  for (i = 1; i <= 1000001; i++) {
    if (cnt[i] >= cnt[m] && i != m) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
