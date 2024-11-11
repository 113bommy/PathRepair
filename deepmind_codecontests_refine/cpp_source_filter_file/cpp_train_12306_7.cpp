#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T, K, fac[27];
  fac[0] = 1, fac[1] = 1;
  for (long long i = 2; i < 20; i++) fac[i] = fac[i - 1] * i;
  cin >> T;
  for (long long i = 0; i < T; i++) {
    cin >> K;
    long long cnt[27], d, now = 0, ans = 1, tmp;
    memset(cnt, 0, sizeof(cnt));
    for (d = 2; K > 0; d++) {
      cnt[K % d]++;
      K /= d;
    }
    ans = 1;
    now = cnt[0];
    for (long long j = 1; j < d - 2; j++) {
      now += cnt[j];
      ans *= now;
      now--;
    }
    for (long long j = 0; j < d - 1; j++) ans /= fac[cnt[j]];
    if (cnt[0]) {
      now = --cnt[0];
      tmp = 1;
      for (long long j = 1; j < d - 3; j++) {
        now += cnt[j];
        tmp *= now;
        now--;
      }
      for (long long j = 0; j < d - 1; j++) tmp /= fac[cnt[j]];
      ans -= tmp;
    }
    cout << ans - 1 << endl;
  }
}
