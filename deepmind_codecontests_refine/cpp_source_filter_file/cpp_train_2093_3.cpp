#include <bits/stdc++.h>
using namespace std;
int n, a[102];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  char c;
  a[0] = 0;
  int nf = n;
  if (n == 1) goto nans;
  for (int i = (1); i != (n + 1); ++i) {
    cin >> c;
    a[i] = (c - '0') + a[i - 1];
  }
  while (a[n] == a[n - 1]) {
    if (n == 1) {
      cout << "NO" << endl;
      return 0;
    }
    n--;
  }
  for (int i = (1); i != (n); ++i) {
    int cur = i;
    bool ok = true;
    for (int j = (i + 1); j != (n + 1); ++j) {
      if (a[j] == 0) continue;
      if (j == n)
        if (a[j] - a[cur] != a[i]) ok = false;
      if (a[j] - a[cur] == a[i]) {
        cur = j;
      } else if (a[j] - a[cur] > a[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
    yans:
      cout << "YES" << endl;
      return 0;
    }
  }
nans:
  cout << "NO" << endl;
  return 0;
}
