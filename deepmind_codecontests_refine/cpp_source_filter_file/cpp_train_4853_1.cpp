#include <bits/stdc++.h>
using namespace std;
const int mxN = 5e5 + 5;
long long a[mxN];
long long pre[mxN];
long long seg(int l, int r) {
  return (r ? pre[r - 1] : 0) - (l ? pre[l - 1] : 0);
}
long long b[mxN];
int ansb[mxN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pre[i] = sum += a[i];
  }
  for (int i = 0; i <= n; i++) {
    b[i] = -1e18;
    for (int j = 0; j <= i; j++) {
      if (seg(0, j) - seg(j, i) > b[i]) {
        b[i] = seg(0, j) - seg(j, i);
        ansb[i] = j;
      }
    }
  }
  long long ans = -1e18;
  int ansi, ansj, ansk;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (b[i] + seg(i, j) - seg(j, n) > ans) {
        ans = b[i] + seg(i, j) - seg(j, n);
        ansi = ansb[i];
        ansj = i;
        ansk = j;
      }
    }
  }
  cout << ansi << " " << ansj << " " << ansk << "\n";
}
