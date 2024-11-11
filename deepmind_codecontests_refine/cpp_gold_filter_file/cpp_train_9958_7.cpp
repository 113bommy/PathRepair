#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    unsigned long long a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    unsigned long long i = 0, j = 0, s1 = a[0], s2 = b[0], cn = 0;
    while (i < n && j < m) {
      if (s1 == s2) {
        cn++;
        i++;
        j++;
        if (i < n) s1 = a[i];
        if (j < m) s2 = b[j];
      } else {
        if (s1 < s2) {
          s1 += a[++i];
        } else
          s2 += b[++j];
      }
    }
    cout << cn;
  }
}
