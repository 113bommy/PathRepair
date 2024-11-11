#include <bits/stdc++.h>
using namespace std;
int setBitNumber(int n) {
  if (n == 0) return -1;
  int msb = 0;
  n = n / 2;
  while (n != 0) {
    n = n / 2;
    msb++;
  }
  return msb;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    map<int, long long> cnt;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int res = setBitNumber(x);
      cnt[res]++;
    }
    long long ans = 0;
    for (auto it : cnt) {
      ans += it.second * (it.second - 1) / 2;
    }
    cout << ans << endl;
  }
  return 0;
}
