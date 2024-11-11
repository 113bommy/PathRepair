#include <bits/stdc++.h>
using namespace std;
constexpr int MAXL = 19;
long long fac[MAXL + 2];
int cnt[MAXL + 2];
long long compute(int l) {
  int cntl = cnt[0] + cnt[1];
  long long res = 1;
  for (int i = 2; i < l; i++) {
    res *= cntl;
    cntl += cnt[i] - 1;
  }
  for (int i = 0; i < l; i++) res /= fac[cnt[i]];
  return res;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i <= MAXL; i++) fac[i] = fac[i - 1] * i;
  int t;
  cin >> t;
  do {
    long long k;
    cin >> k;
    fill(cnt, cnt + MAXL, 0);
    int l = 2;
    for (; l <= MAXL && k; l++) {
      cnt[k % l]++;
      k /= l;
    }
    long long res = compute(l) - 1;
    if (cnt[0]) {
      cnt[0]--;
      res -= compute(l - 1);
    }
    cout << res << '\n';
  } while (--t);
}
