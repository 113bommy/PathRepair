#include <bits/stdc++.h>
using namespace std;
int main() {
  int j, i, z = 0, n, a[100005], cnt = 0, s = 0, mx = -1;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  while (z < n) {
    i = z;
    int rep = 1 + cnt;
    for (j = i + 1; j < n; j++)
      if (i != j && a[j] == a[i])
        rep++, i = j;
      else if (a[j] > a[i])
        break;
    if (rep & 1) s++, z++, mx = max(mx, a[i]);
    cnt = rep / 2;
    z += cnt;
    for (; cnt > 0; i--, cnt--) a[i]++;
  }
  cout << mx - s + 1 << endl;
  return 0;
}
