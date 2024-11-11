#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int pos, p, q, n, m, i, j, x, y, e, t, T, ans, cnt, mn, sum, mx, f,
      c, k, l, r;
  bool flag;
  t = 1;
  while (t--) {
    cin >> n;
    ans = 0;
    string str;
    cin >> str;
    char a[] = {'R', 'G', 'B'};
    for (i = 0; i < n; i++) {
      if (i + 1 < n && i + 2 < n && str[i] == str[i + 1]) {
        ans++;
        for (j = 0; j < 3; j++) {
          if (a[j] != str[i] && a[j] != str[i + 2]) {
            str[i + 1] = a[j];
            break;
          }
        }
        i++;
      } else if (i + 1 < n && str[i] == str[i + 1]) {
        ans++;
        for (j = 0; j < 3; j++) {
          if (a[j] != str[i]) {
            str[i + 1] = a[j];
            break;
          }
        }
        i++;
      }
    }
    cout << ans << "\n";
    cout << str << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
