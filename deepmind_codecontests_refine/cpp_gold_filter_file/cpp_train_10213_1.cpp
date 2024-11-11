#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
map<long long, int> mp[15];
long long a[maxn], c[maxn], d[maxn];
long long Pow[15];
long long ans = 0LL;
int main() {
  int n, k;
  long long cnt, num;
  cin >> n >> k;
  Pow[0] = 1LL;
  for (int i = 1; i <= 10; i++) Pow[i] = Pow[i - 1] * 10;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt = 0, num = a[i];
    while (num) {
      cnt++;
      num /= 10;
    }
    c[i] = cnt;
    d[i] = a[i] % k;
  }
  num = 1LL;
  for (int i = 1; i <= 10; i++) {
    num *= 10;
    for (int j = 1; j <= n; j++) {
      cnt = d[j] * (num % k);
      cnt %= k;
      if (!mp[i].count(cnt))
        mp[i][cnt] = 1;
      else
        mp[i][cnt]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    int md = (k - d[i]) % k;
    if (mp[c[i]].count(md)) {
      ans += mp[c[i]][md];
      num = Pow[c[i]];
      if ((d[i] * num % k) % k == md) ans--;
    }
  }
  cout << ans << endl;
}
