#include <bits/stdc++.h>
using namespace std;
const int maxn = 10100;
const int INF = 1 << 30;
const int MOD = 1e9 + 7;
const double dif = 1e-5;
int n, p;
int a[maxn], b[maxn];
bool check(double x) {
  double sum = 0;
  for (int i = 0; i < n; i++) sum += max(0.0, a[i] * x - b[i]);
  if (sum < x * p)
    return true;
  else
    return false;
}
int main(void) {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m--) {
      int l, r, x, cnt = 0;
      cin >> l >> r >> x;
      for (int i = l; i <= r; i++)
        if (a[i] < a[x]) cnt++;
      if (cnt == x - l)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}
