#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001], b[200001];
long long x, k, y;
void read() {
  cin >> n >> m >> x >> k >> y;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
}
bool update(int l, int r, long long &res) {
  if (l > r) return true;
  bool ok = false;
  int maxx = *max_element(a + l, a + r + 1);
  int lr = r - l + 1;
  if ((l - 1 >= 0 && a[l - 1] > maxx) || (r + 1 < n && a[r + 1] > maxx))
    ok = true;
  if (lr < k && !ok) return false;
  int need = lr % k;
  res += need * y;
  lr -= need;
  if (y * k >= x)
    res += lr / k * x;
  else if (ok)
    res += lr * y;
  else
    res += (lr - k) * y + x;
  return true;
}
int main() {
  read();
  long long res = 0;
  int posA = 0, posB = 0, last = -1;
  while (posB < m) {
    while (posA < n && a[posA] != b[posB]) ++posA;
    if (posA == n) {
      cout << -1;
      return 0;
    }
    if (!update(last + 1, posA - 1, res)) {
      cout << -1;
      return 0;
    }
    last = posA;
    ++posB;
  }
  if (!update(last + 1, n - 1, res)) {
    cout << -1;
    return 0;
  }
  cout << res;
  return 0;
}
