#include <bits/stdc++.h>
using namespace std;
int pr[2][10000000];
int k, h, g, n;
string a;
bool check(int m, int p) {
  int ch1, ch2;
  if (m >= p)
    ch2 = 0;
  else if (m != 0)
    ch2 = pr[0][p - m - 1];
  else
    ch2 = pr[0][p];
  if ((m + p) >= n)
    ch1 = pr[0][n - 1];
  else
    ch1 = pr[0][m + p];
  return (ch1 - ch2) >= (k + 1);
}
long long bns(int len) {
  long long fans = 1000000000;
  for (int i = 0; i < len; i++) {
    if (a[i] == '1') continue;
    long long ans = 100000000;
    int l = i, r = len - 1, mid = 0;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (check(mid, i))
        r = mid - 1, ans = mid;
      else
        l = mid + 1;
      fans = min(fans, ans);
    }
  }
  return fans;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  cin >> a;
  pr[1][0] = a[0] == '1';
  pr[0][0] = a[0] == '0';
  for (int i = 1; i < n; i++) {
    if (a[i] == '1')
      pr[1][i] = pr[1][i - 1] + 1, pr[0][i] = pr[0][i - 1];
    else
      pr[0][i] = pr[0][i - 1] + 1, pr[1][i] = pr[1][i - 1];
  }
  cout << bns(n) << endl;
  return 0;
}
