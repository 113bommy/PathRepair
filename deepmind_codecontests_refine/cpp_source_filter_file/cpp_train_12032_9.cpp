#include <bits/stdc++.h>
using namespace std;
int n, t, _ind;
int tot[16], cho[16];
long long mem[205][205], f[205][205];
long long C(int n, int m) {
  if (mem[n][m]) return mem[n][m];
  long long ret = 1;
  for (int i = n; i >= n - m + 1; i--) ret = ret * i / (n - i + 1);
  return mem[n][m] = ret;
}
long long dp1(int len) {
  if (len == 0) return 1;
  memset(f, 0, sizeof(f));
  f[0][0] = 1;
  for (int i = 1; i <= 16; i++) {
    for (int j = 0; j <= len; j++)
      for (int k = 0; k <= tot[i] && k <= j; k++)
        f[i][j] += f[i - 1][j - k] * C(j, k);
  }
  return f[16][len];
}
long long dp2(int len) {
  long long ret = 0;
  for (int i = 2; i <= 16; i++) {
    if (tot[i]) {
      tot[i]--;
      ret += dp1(len - 1);
      tot[i]++;
    }
  }
  return ret;
}
int main() {
  cin >> n >> t;
  for (int i = 1; i <= 16; i++) tot[i] = t;
  for (int i = 1; i <= 18; i++) {
    long long k = dp2(i);
    if (k >= n) {
      _ind = i;
      break;
    }
    n -= k;
  }
  for (int i = _ind; i >= 1; i--) {
    for (int j = 1; j <= 16; j++) {
      if (i == _ind && j == 1) continue;
      if (tot[j] == 0) continue;
      tot[j]--;
      long long ret = dp1(i - 1);
      if (ret >= n) {
        cho[i] = j;
        break;
      }
      tot[j]++;
      n -= ret;
    }
  }
  for (int i = _ind; i >= 1; i--) {
    if (cho[i] <= 10)
      cout << cho[i] - 1;
    else
      cout << (char)('a' + cho[i] - 11);
  }
  return 0;
}
