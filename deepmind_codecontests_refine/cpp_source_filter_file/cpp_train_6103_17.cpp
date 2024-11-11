#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 12, mod = 1e9 + 7;
int n, a[maxn], b[maxn], t[maxn], cnt[maxn], p[maxn], res[maxn], ans;
int q(int x, int y) {
  int c;
  cout << "? " << x << ' ' << y << endl;
  cin >> c;
  return c;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) a[i] = q(i, 0);
  for (int i = 0; i < n; i++) b[i] = q(0, i);
  for (int i = 0; i < n; i++) {
    bool ok = 1;
    for (int j = 0; j < n; j++) p[j] = 0, cnt[j] = 0;
    for (int j = 0; j < n; j++) t[j] = i ^ a[j];
    for (int j = 0; j < n; j++) cnt[t[j]]++;
    for (int j = 0; j < n; j++)
      if (cnt[j] > 1 || cnt[j] < 1) ok = 0;
    for (int j = 0; j < n; j++) p[t[j]] = j;
    for (int j = 0; j < n; j++)
      if ((p[j] ^ t[0]) != b[j]) ok = 0;
    if (ok) {
      ans++;
      for (int j = 0; j < n; j++) res[j] = p[j];
    }
  }
  cout << "!" << endl;
  cout << ans << endl;
  for (int i = 0; i < n; i++) cout << res[i] << endl;
  return 0;
}
