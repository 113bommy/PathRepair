#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long ma = 823543;
long long fac[7][823543];
bool rep[823543];
int dig[823543];
int main() {
  long long i, j, k, m, n;
  cin >> n >> m;
  if (n - 1 >= ma || m - 1 >= ma) {
    cout << 0;
    return 0;
  }
  for (i = 0; i < 7; ++i) memset(fac[i], 0, sizeof(fac[i]));
  memset(rep, true, sizeof(rep));
  memset(dig, 0, sizeof(dig));
  for (i = 0; i < ma; ++i) {
    long long v = i;
    while (v > 0) {
      int d = v % 7;
      fac[d][i]++;
      v /= 7;
      dig[i]++;
    }
    for (j = 0; j < 7; ++j) {
      if (fac[j][i] > 1) {
        rep[i] = false;
        break;
      }
    }
  }
  dig[0] = 1;
  fac[0][0] = 1;
  if (dig[m - 1] + dig[n - 1] > 7) {
    cout << 0;
    return 0;
  }
  long long ans = 0;
  long long m1 = 0, n1 = 0;
  while (true) {
    if (dig[m1] + 2 <= dig[m - 1])
      ++m1;
    else
      break;
  }
  while (true) {
    if (dig[n1] + 2 <= dig[n - 1])
      ++n1;
    else
      break;
  }
  for (i = m1; i < m; ++i) {
    if (dig[i] + 2 <= dig[m - 1]) continue;
    if (rep[i] == false) continue;
    for (j = n1; j < n; ++j) {
      if (dig[j] + 2 <= dig[n - 1]) continue;
      if (rep[j] == false) continue;
      long long ch[7];
      memset(ch, 0, sizeof(ch));
      for (k = 0; k < 7; ++k) ch[k] = fac[k][i] + fac[k][j];
      bool g = true;
      if (dig[i] == dig[m - 1] - 1) ++ch[0];
      if (dig[j] == dig[n - 1] - 1) {
        ++ch[0];
      }
      for (k = 0; k < 7; ++k) {
        if (ch[k] > 1) {
          g = false;
          break;
        }
      }
      if (g == true) {
        ++ans;
      }
    }
  }
  cout << ans << "\n";
}
