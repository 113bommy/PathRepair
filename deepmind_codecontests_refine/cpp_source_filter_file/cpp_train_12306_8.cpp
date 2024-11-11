#include <bits/stdc++.h>
using namespace std;
int t;
vector<long long> fact;
long long calc(vector<long long>& fp, int m) {
  long long mm = fp[0] + fp[1];
  long long res = mm;
  for (int i = 3; i <= m & m > 0; i++) {
    mm--;
    mm += fp[i - 1];
    res *= mm;
  }
  for (int i = 0; i <= m; i++) {
    if (fp[i] > 1) {
      res /= fact[fp[i]];
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  fact = vector<long long>(21, 0);
  fact[0] = 1;
  for (int i = 1; i <= 20; ++i) fact[i] = fact[i - 1] * i;
  long long k;
  vector<long long> ans;
  for (int i = 0; i < t; ++i) {
    cin >> k;
    vector<long long> fp(21, 0);
    long long f = 0;
    long long l = 0;
    for (int j = 2; j < 20; j++) {
      fp[k % j]++;
      k = k / j;
      if (k == 0) {
        f = calc(fp, j);
        if (fp[0] > 0) {
          fp[0]--;
          l = calc(fp, j - 1);
        }
        ans.push_back(f - l - 1);
        break;
      }
    }
  }
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
  return 0;
}
