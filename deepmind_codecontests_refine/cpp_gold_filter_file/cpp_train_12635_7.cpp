#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a;
  int bf;
  for (int i = 0; i < n; i++) {
    scanf("%d", &bf);
    a.push_back(bf);
  }
  sort(a.begin(), a.end());
  int mn = 0;
  for (int i = 0; i < n; i++)
    if (abs(a[i]) < abs(a[mn])) {
      mn = i;
    }
  for (int i = 0; i < n && k > 0; i++) {
    if (a[i] < 0) {
      a[i] *= -1;
      k--;
    }
  }
  if (k % 2) a[mn] *= -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i];
  }
  cout << ans;
  return 0;
}
