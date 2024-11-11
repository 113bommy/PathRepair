#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAX = 3000;
const int inf = 999999999;
const int p1 = 104393321, p2 = 104393329;
int n;
int c[MAX], r[MAX], d[MAX];
string a[MAX];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = (0); i < int(n); ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = (0); i < int(n); ++i) {
    for (int j = (n - 1); j > int(i); --j) {
      if ((r[i] + c[j]) % 2 == a[i][j] - '0')
        continue;
      else {
        r[i]++;
        c[j]++;
        ans++;
        d[i]++;
        d[j]++;
      }
    }
  }
  memset(r, 0, sizeof r);
  memset(c, 0, sizeof c);
  for (int i = (n - 1); i > int(-1); --i) {
    for (int j = (0); j < int(i); ++j) {
      if ((r[i] + c[j]) % 2 == a[i][j] - '0')
        continue;
      else {
        r[i]++;
        c[j]++;
        d[i]++;
        d[j]++;
        ans++;
      }
    }
  }
  for (int i = (0); i < int(n - 1); ++i) {
    if (d[i] % 2 == a[i][i] - '0')
      continue;
    else {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
