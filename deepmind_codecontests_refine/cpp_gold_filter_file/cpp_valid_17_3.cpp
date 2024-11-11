#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
bool comp(vector<long long> a, vector<long long> b) {
  long long cnt1 = 0, cnt2 = 0;
  for (long long i = long long(0); i <= long long(4); i++) {
    if (a[i] < b[i])
      cnt1++;
    else
      cnt2++;
  }
  return cnt1 > cnt2;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n, i, j, k, l, m;
    cin >> n;
    vector<vector<long long> > r(n, vector<long long>(5));
    for (long long i = long long(0); i <= long long(n - 1); i++)
      for (long long j = long long(0); j <= long long(4); j++) cin >> r[i][j];
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    vector<vector<long long> > z = r;
    sort(r.begin(), r.end(), comp);
    long long cnt = 0;
    for (long long i = long long(1); i <= long long(n - 1); i++) {
      long long temp = 0;
      for (long long j = long long(0); j <= long long(4); j++) {
        if (r[0][j] < r[i][j]) temp++;
      }
      if (temp >= 3)
        cnt++;
      else
        break;
    }
    if (cnt == n - 1) {
      for (long long i = long long(0); i <= long long(n - 1); i++) {
        long long temp = 0;
        for (long long j = long long(0); j <= long long(4); j++) {
          if (r[0][j] == z[i][j]) temp++;
        }
        if (temp == 5) {
          cout << i + 1 << "\n";
          break;
        }
      }
    } else
      cout << "-1\n";
  }
  return 0;
}
