#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long depe[505][505];
long long sim[505];
long long res;
long long dp(int now, int sisa) {
  if (now > n) {
    return 1;
  }
  long long &ret = depe[now][sisa];
  if (ret != -1) return ret;
  ret = 0;
  if (sisa > 0) {
    ret = (ret + dp(now + 1, sisa - 1)) % 998244353;
  }
  ret = (ret + dp(now + 1, res - 1));
  return ret;
}
int main() {
  cin >> n >> k;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  long long bawa = 0;
  for (int i = 1; i <= n; i++) {
    res = i;
    memset(depe, -1, sizeof(depe));
    sim[i] = (dp(2, i - 1) - bawa) % 998244353;
    sim[i] += 998244353;
    sim[i] %= 998244353;
    bawa = (bawa + sim[i]) % 998244353;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int kali = i * j;
      if (kali < k) {
        long long tamb = (sim[i] * sim[j]) % 998244353;
        tamb = (tamb * 2) % 998244353;
        ans = (ans + tamb) % 998244353;
      }
    }
  }
  cout << ans << "\n";
}
