#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (long long &first : a) cin >> first;
    for (long long &first : b) cin >> first;
    bool flag = false;
    for (long long i = 0; i < n; i++) {
      if (b[i] >= a[i]) {
        long long pos = i;
        long long last = a[i];
        flag = true;
        while (pos < 2 * n) {
          if (b[pos % n] < last) {
            flag = false;
            break;
          }
          long long req = last + a[(pos + 1) % n];
          last = max(req - b[pos], 0LL);
          pos++;
        }
        if (flag) {
          break;
        }
        if ((pos % n) < i)
          break;
        else
          i = pos % n;
        flag = false;
      }
    }
    if (flag)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
