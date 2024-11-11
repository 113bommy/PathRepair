#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 6;
const long long MOD = 1e9 + 7;
int a[2005];
int cnt[5005], suf[5005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long double tot = 0.5 * n * (n - 1);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cnt[a[j] - a[i]]++;
    }
  }
  for (int i = 4999; i >= 1; i--) suf[i] = suf[i + 1] + cnt[i];
  long double res = 0.0;
  for (int i = 1; i < 5000; i++) {
    for (int j = i; j < 5000; j++) {
      if (i + j + 1 >= 5000) continue;
      if (!cnt[i] or !cnt[j]) continue;
      long double cur = 1.0;
      cur *= (long double)cnt[i] / tot;
      cur *= (long double)cnt[j] / tot;
      cur *= (long double)suf[i + j + 1] / tot;
      res += cur;
    }
  }
  cout << fixed << setprecision(10) << res;
}
