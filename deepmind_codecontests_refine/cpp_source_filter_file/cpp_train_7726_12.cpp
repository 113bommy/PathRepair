#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long t, n;
    cin >> t >> n;
    vector<long long> v(40);
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      long long cnt = 0;
      while (a != 1) {
        cnt++;
        a >>= 1;
      }
      v[cnt]++;
    }
    vector<long long> num(70);
    long long x = 0;
    while (t != 0) {
      if (t & 1) num[x] = 1;
      x++;
      t = t >> 1;
    }
    long long ih = 0, ans = 0;
    for (long long i = 0; i < 32; i++) {
      ih /= 2;
      if (num[i] == 1 && ih >= 1) {
        ih--;
        num[i] = 0;
      } else if (v[i] >= 1 && num[i] == 1) {
        num[i] = 0;
        v[i]--;
      }
      long long mi = i;
      if (v[i]) {
        for (long long j = i - 1; j >= 0; j--) {
          if (num[j]) {
            num[j] = 0;
            mi = j;
          }
        }
      }
      if (mi != i) {
        v[i]--;
        ans += (i - mi);
      }
      ih += v[i];
    }
    long long flag = 0;
    for (long long i = 0; i < 64; i++) {
      if (num[i] == 1) flag = 1;
    }
    if (flag == 1)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
