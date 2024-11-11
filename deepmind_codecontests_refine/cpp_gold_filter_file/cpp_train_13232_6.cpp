#include <bits/stdc++.h>
using namespace std;
long long a[100005] = {0};
int b[100005] = {0};
int c[100005] = {0};
int main() {
  int n, m, l;
  cin >> n >> m >> l;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  a[0] = l + 1;
  a[n + 1] = l + 1;
  int j = 1;
  bool b;
  int sum = 0;
  while (j <= n) {
    while (j <= n && a[j] <= l) j++;
    if (j <= n) sum++;
    while (j <= n && a[j] > l) j++;
  }
  for (int i = 0; i < m; ++i) {
    int temp;
    cin >> temp;
    if (temp == 1) {
      int p, v;
      cin >> p >> v;
      a[p] += v;
      if (a[p] > l && a[p] - v <= l) {
        if ((p - 1 > 0 && a[p - 1] > l) && (p + 1 <= n && a[p + 1] > l))
          sum--;
        else if ((p - 1 <= 0 || a[p - 1] <= l) && (p + 1 > n || a[p + 1] <= l))
          sum++;
      }
    } else {
      cout << sum << endl;
    }
  }
  return 0;
}
