#include <bits/stdc++.h>
using namespace std;
int n, anss[300010], num[300010], cnt[2] = {1};
long long ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    long long x;
    cin >> x;
    while (x > 0) {
      num[i] += (x % 2);
      x /= 2;
    }
    anss[i] = anss[i - 1] + num[i];
    ans += cnt[anss[i] % 2];
    for (int j = i, k = i + 1, maxn = 0; j >= 1 && j >= i - 64; --j) {
      while (k > j) maxn = max(maxn, num[--k]);
      if (maxn * 2 > anss[i] - anss[j - 1] && anss[i] % 2 == anss[j - 1] % 2)
        --ans;
    }
    ++cnt[anss[i] % 2];
  }
  cout << ans << endl;
  return 0;
}
