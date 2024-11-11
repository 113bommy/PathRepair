#include <bits/stdc++.h>
using namespace std;
const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const long double Inf = 1LL << 62;
long double ar[Max];
long double nxt[Max];
long double cum[Max];
long double zr[Max];
int main() {
  long double n, k, cnt = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%Lf", &ar[i]);
    cum[i] += cum[i - 1] + ar[i];
  }
  int nx = n + 1;
  for (int i = n; i >= 1; i--) {
    nxt[i] = i + 1;
    zr[i] = nx;
    if (ar[i] != 1) nx = i;
  }
  for (int i = 1; i <= n; i++) {
    long double cur = 1, prv = i - 1;
    for (int j = i; j <= n; j = zr[j]) {
      cur *= ar[j];
      long double sum = cum[j] - cum[i - 1];
      if (cur > cum[(int)n] * k) break;
      if (cur == sum * k) cnt++;
      if (abs(zr[j] - j) < 2) continue;
      int l = j + 1, r = zr[j] - 1;
      bool f = 0;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (k * (cum[mid] - cum[i - 1]) == cur) {
          f = 1;
          break;
        } else if (k * (cum[mid] - cum[i - 1]) > cur) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      cnt += f;
    }
  }
  cout << cnt << endl;
  return 0;
}
