#include <bits/stdc++.h>
using namespace std;
const long long N = 205;
string arr[N];
long long ans[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  long long m;
  cin >> m;
  auto get = [&](long long a) {
    for (long long i = 1; i <= 10; i++) {
      for (long long j = 0; j < (1 << i); j++) {
        string s(i, '0');
        for (long long k = 0; k < i; k++) {
          if (j & (1 << k)) s[k] = '1';
        }
        if (arr[a].find(s) == -1) return i - 1;
      }
    }
  };
  for (long long i = 1; i <= m; i++) {
    long long l, r;
    cin >> l >> r;
    arr[i + n] = arr[l] + arr[r];
    ans[i + n] = max({ans[l], ans[r], get(i + n)});
    if (arr[i + n].size() > 2000)
      arr[i + n] = arr[i + n].substr(0, 1000) +
                   arr[i + n].substr(arr[i + n].size() - 1000);
    cout << ans[i + n] << "\n";
  }
}
