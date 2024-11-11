#include <bits/stdc++.h>
using namespace std;
const int maxn = 300500;
int n, k;
int a[maxn];
int psa[maxn];
signed main() {
  ios::sync_with_stdio(0);
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psa[i] = psa[i - 1] + a[i];
  }
  int ma = 0;
  int mal = -1, mar = -1;
  for (int i = 1; i <= n; i++) {
    int l = i;
    int r = n;
    int lastgood = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      int len = m - i + 1;
      int ops = len - (psa[m] - psa[i - 1]);
      if (ops <= k) {
        l = m + 1;
        lastgood = m;
      } else {
        r = m - 1;
      }
    }
    if (lastgood - i + 1 > ma) {
      ma = lastgood - i + 1;
      mal = i;
      mar = lastgood;
    }
  }
  cout << ma << '\n';
  for (int i = 1; i <= n; i++) {
    if (mal <= i and i <= mar) {
      cout << 1 << " ";
    } else {
      cout << a[i] << " ";
    }
  }
  cout << '\n';
}
