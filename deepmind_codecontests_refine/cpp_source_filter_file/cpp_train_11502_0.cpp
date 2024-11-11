#include <bits/stdc++.h>
using namespace std;
const int maxN = 101000;
int n, m, a[100], b[100], res;
void init() { cin >> n >> m; }
void xuat(int l, int r) {
  if (l <= 0 || r <= 0) return;
  if (l <= r)
    for (int i = l; i < r + 1; i++) printf("%i ", i);
  else
    for (int i = l; i > r - 1; i--) printf("%i ", i);
}
void dq(int k) {
  if (k > n) {
    int ans = 0;
    for (int i = 1; i < n + 1; i++) {
      int ht = n + 1;
      for (int j = i; j < n + 1; j++) {
        ht = min(ht, a[j]);
        ans += ht;
      }
    }
    res = max(ans, res);
    return;
  }
  for (int i = 1; i < n + 1; i++)
    if (b[i] == 0) {
      b[i] = 1;
      a[k] = i;
      dq(k + 1);
      b[i] = 0;
    }
}
void dq1(int k) {
  if (k > n) {
    int ans = 0;
    for (int i = 1; i < n + 1; i++) {
      int ht = n + 1;
      for (int j = i; j < n + 1; j++) {
        ht = min(ht, a[j]);
        ans += ht;
      }
    }
    if (ans == res) {
      --m;
      if (m != 0) return;
      for (int i = 1; i < n + 1; i++) printf("%i", a[i]);
      cout << "\n";
    }
    return;
  }
  for (int i = 1; i < n + 1; i++)
    if (b[i] == 0) {
      b[i] = 1;
      a[k] = i;
      dq1(k + 1);
      b[i] = 0;
    }
}
void xuly() {
  int tm = m;
  dq(1);
  dq1(1);
}
int main() {
  init();
  xuly();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
