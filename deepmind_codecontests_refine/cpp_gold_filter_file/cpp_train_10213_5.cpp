#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    long long int i, j, n, k;
    cin >> n >> k;
    vector<long long int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int pwr[11];
    pwr[0] = 1;
    for (long long int i = 0; i < 10; i++) {
      pwr[i + 1] = (pwr[i] * 10) % k;
    }
    vector<vector<long long int>> rem(12);
    vector<long long int> len(n, 0);
    for (long long int i = 0; i < n; i++) {
      long long int temp = a[i];
      long long int cnt = 0;
      while (temp) {
        cnt++;
        temp /= 10;
      }
      len[i] = cnt;
      rem[cnt].push_back(a[i] % k);
    }
    for (long long int i = 0; i < rem.size(); i++)
      sort(rem[i].begin(), rem[i].end());
    long long int ans = 0;
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 1; j < 11; j++) {
        long long int temp = (k - (a[i] * pwr[j]) % k) % k;
        long long int lo =
            lower_bound(rem[j].begin(), rem[j].end(), temp) - rem[j].end();
        long long int up =
            upper_bound(rem[j].begin(), rem[j].end(), temp) - rem[j].end();
        ans += up - lo;
        if (len[i] == j && (k - temp + a[i] % k) % k == 0) {
          ans--;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
