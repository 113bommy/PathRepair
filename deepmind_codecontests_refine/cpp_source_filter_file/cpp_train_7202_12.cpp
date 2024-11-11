#include <bits/stdc++.h>
using namespace std;
long long a[2222];
int ans = 0;
void init(long long num) {
  if (num >= 1e9)
    return;
  else
    a[ans++] = num;
  init(num * 10 + 4);
  init(num * 10 + 7);
}
int main() {
  init(0);
  sort(a, a + ans);
  int n, m, l, r, mid;
  long long sum;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n < 1 && m < 1) break;
    l = 0, r = 0;
    for (int i = 1; i < ans; i++) {
      if (a[i] >= n && l == 0) l = i;
      if (a[i] >= m && r == 0) r = i;
      if (l && r) break;
    }
    sum = 0;
    if (l == r) {
      for (int i = n; i <= m; i++) {
        sum += a[l];
      }
    } else {
      sum += (a[l] - n + 1) * a[l];
      for (int i = l + 1; i <= ans; i++) {
        if (a[i] >= m) {
          sum += (m - a[i - 1]) * a[i];
          break;
        } else {
          sum += (a[i] - a[i - 1]) * a[i];
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
