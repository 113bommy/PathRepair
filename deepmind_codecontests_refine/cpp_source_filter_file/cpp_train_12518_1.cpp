#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int power(int first, int second) {
  int res = 1;
  while (second) {
    if (second % 2) res = 1LL * res * first % MOD;
    first = 1LL * first * first % MOD;
    second >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int ntest;
  cin >> ntest;
  while (ntest--) {
    int n, p;
    cin >> n >> p;
    vector<int> k(n);
    for (int &e : k) cin >> e;
    if (p == 1) {
      cout << n % 2 << '\n';
      continue;
    }
    int res = 0;
    long long cnt = 1;
    sort(k.begin(), k.end());
    reverse(k.begin(), k.end());
    int cur = k[0];
    cnt = 1;
    res = power(p, k[0]);
    bool check = 0;
    for (int i = 1; i < k.size(); i++) {
      if (check) {
        res = (res - power(p, k[i])) % MOD;
        continue;
      }
      if (cnt == 0) {
        cnt = 1;
        cur = k[i];
        res = (res + power(p, k[i])) % MOD;
      } else {
        int t = cur - k[i];
        for (int j = 0; j < t; j++) {
          cnt = cnt * p;
          if (cnt > 1e7) {
            check = 1;
            break;
          }
        }
        cur = k[i];
        cnt--;
        res = (res - power(p, k[i]) + MOD) % MOD;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
