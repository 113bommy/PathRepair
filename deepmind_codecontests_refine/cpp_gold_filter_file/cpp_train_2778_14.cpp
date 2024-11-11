#include <bits/stdc++.h>
using namespace std;
long long n;
long long memo[(int)3e7 + 5], fac[20];
bool flag = 0;
int idx[15], base[15];
long long dp() {
  int id = 0;
  for (int i = 0; i < 10; ++i) id += idx[i] * base[i];
  if (memo[id] != -1) return 0;
  int tmp = 0;
  for (int i = 0; i < 10; ++i) tmp += idx[i];
  memo[id] = fac[tmp];
  for (int i = 0; i < 10; ++i) memo[id] /= fac[idx[i]];
  for (int i = 0; i < 10; ++i)
    if (idx[i] > 1 || (i == 0 && flag && idx[0] == 1)) {
      idx[i]--;
      memo[id] += dp();
      idx[i]++;
    }
  return memo[id];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fac[0] = 1;
  for (int i = 1; i <= 19; ++i) fac[i] = fac[i - 1] * i;
  cin >> n;
  long long m = n;
  while (m > 0) {
    idx[m % 10]++;
    m /= 10;
  }
  base[9] = 1;
  for (int i = 8; i >= 0; --i) base[i] = max(idx[i + 1], 1) * base[i + 1];
  memset(memo, -1, sizeof memo);
  long long res = dp();
  if (idx[0] > 0) {
    memset(memo, -1, sizeof memo);
    flag = 1;
    idx[0]--;
    res -= dp();
  }
  cout << res;
}
