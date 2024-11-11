#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 998244353;
const long long N = 2e6 + 7;
void solve() {
  long long n;
  string str;
  cin >> str;
  n = str.size();
  long long pow2[18];
  pow2[0] = 1;
  for (int i = 1; i < 18; i++) {
    pow2[i] = pow2[i - 1] * 2;
  }
  vector<long long> precal(n + 1);
  for (int i = 0; i < n;) {
    if (str[i] == '0') {
      int cnt = 1;
      int j = i + 1;
      precal[i] = cnt;
      while (j < n && str[j] == '0') {
        precal[j] = ++cnt;
        j++;
      }
      i = j;
    } else {
      i++;
    }
  }
  long long cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    long long val = 0;
    for (int j = i, k = 1; j >= max(i - 17, 0);) {
      if (str[j] == '1') {
        val += pow2[k - 1];
        if (val == k) {
          cnt++;
        }
        j--;
        k++;
      } else {
        if (val >= k && val <= k + precal[j] - 1) {
          cnt++;
        }
        k += precal[j];
        j -= precal[j];
      }
    }
  }
  cout << cnt;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
