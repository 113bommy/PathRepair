#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], ma[N], mi[N], f[N], q[N], v[N];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int p = 0;
  cin >> a[1];
  mi[++p] = a[1];
  ma[1] = 1;
  q[1] = 1;
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
    if (a[i] > mi[p]) {
      mi[++p] = a[i];
      q[i] = p;
    } else {
      int x = lower_bound(mi + 1, mi + p + 1, a[i]) - mi;
      mi[x] = a[i];
      q[i] = x;
    }
  }
  ma[p + 1] = a[n + 1] = 1e9;
  int k = p;
  for (int i = n; i >= 1; i--) {
    if (q[i] == k) {
      ma[k] = a[i];
      mi[k--] = i;
    } else if (q[i] >= k && a[i] < ma[q[i] + 1]) {
      f[q[i]] = 2;
      ma[q[i]] = a[i];
    }
  }
  k = p;
  memset(ma, 0, sizeof ma);
  ma[p + 1] = 0x3f3f3f3f;
  for (int i = n; i >= 1; i--) {
    if (q[i] >= k && a[i] < ma[q[i] + 1]) {
      ma[q[i]] = max(ma[q[i]], a[i]);
      if (f[q[i]] == 2)
        v[i] = 2;
      else
        v[i] = 3;
    } else
      v[i] = 1;
    if (a[i] == k) k--;
  }
  for (int i = 1; i <= n; i++) {
    cout << v[i];
  }
  cout << endl;
  return 0;
}
