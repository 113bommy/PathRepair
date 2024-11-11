#include <bits/stdc++.h>
using namespace std;
int n, a[300005];
vector<pair<int, int> > q1, q2;
int res[300005];
int d[3000005];
void update(int k, int p, int q, int x, int y, int z) {
  if (x > y || p > y || x > q) return;
  if (x <= p && q <= y) {
    d[k] = z;
    return;
  }
  if (d[k] != 0) {
    d[2 * k] = d[k];
    d[2 * k + 1] = d[k];
    d[k] = 0;
  }
  update(2 * k, p, (p + q) / 2, x, y, z);
  update(2 * k + 1, (p + q) / 2 + 1, q, x, y, z);
}
int get(int k, int p, int q, int x) {
  if (p > x || q < x) return 0;
  if (p == q) return d[k];
  if (d[k] != 0) {
    d[2 * k] = d[k];
    d[2 * k + 1] = d[k];
    d[k] = 0;
  }
  return max(get(2 * k, p, (p + q) / 2, x),
             get(2 * k + 1, (p + q) / 2 + 1, q, x));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    q1.push_back(pair<int, int>(a[i], i));
    res[n - 1] = max(res[n - 1], a[i]);
    if (n > 1) res[n - 2] = max(res[n - 2], a[i]);
  }
  sort(q1.begin(), q1.end());
  for (int i = 1; i < n; i++) {
    q2.push_back(pair<int, int>(min(a[i], a[i + 1]), i));
  }
  sort(q2.begin(), q2.end());
  for (int i = 0; i < (int)q1.size(); i++) {
    int pos = q1[i].second, val = q1[i].first;
    if (pos > 1) update(1, 1, n, 1, min(pos - 2, n - pos), val);
    if (pos < n) update(1, 1, n, 1, min(pos - 1, n - pos - 1), val);
  }
  for (int i = 1; n - 2 - (2 * i) >= 0; i++)
    res[n - 2 - (2 * i)] = get(1, 1, n, i);
  memset(d, 0, sizeof(d));
  for (int i = 0; i < (int)q2.size(); i++) {
    int pos = q2[i].second, val = q2[i].first;
    if (pos > 1 || pos + 2 <= n) res[n - 3] = max(res[n - 3], val);
    update(1, 1, n, 1, min(pos - 1, n - pos - 2), val);
    update(1, 1, n, 1, min(pos - 3, n - pos), val);
  }
  for (int i = 1; n - 3 - (2 * i) >= 0; i++)
    res[n - 3 - (2 * i)] = get(1, 1, n, i);
  for (int i = 0; i < n; i++) {
    assert(res[i] != 0);
    printf("%d ", res[i]);
    printf("\n");
  }
  return 0;
}
