#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, p, x, y, a[1010], i, j, b[1010], mid, sum = 0;
  cin >> n >> k >> p >> x >> y;
  for (i = 0; i < k; i++) cin >> a[i], sum += a[i];
  vector<int> v;
  memset(b, 0, sizeof b);
  sort(a, a + k);
  mid = n / 2;
  if (k > mid && a[mid] < y) {
    puts("-1");
    return 0;
  }
  int chk, need;
  chk = n - 1;
  int pos = -1;
  for (i = k - 1; i >= 0; i--)
    if (a[i] >= y) b[chk--] = a[i], pos = i;
  need = x - sum;
  if (!b[mid]) {
    for (i = mid; !b[i] && i < n; i++) b[i] = y, need -= y, v.push_back(y);
    j = k - 1;
    for (i = mid - 1; i >= 0 && j >= 0; j--) {
      if (a[j] < y) b[i] = a[j], i--;
    }
  } else {
    v.clear();
    for (i = pos - 1; i >= 0; i--) b[chk--] = a[i];
  }
  for (i = 0; i < n; i++) {
    if (!b[i]) b[i] = 1, need--, v.push_back(1);
  }
  if (need < 0)
    puts("-1");
  else {
    j = v.size();
    for (i = 0; i < j; i++) cout << v[i] << " ";
    cout << endl;
  }
  return 0;
}
