#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
long long a[N], b, c, d, dis;
pair<int, int> p;
bool mark = true;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, n, m, k, ans = 0, sum = 0, mn = 1e8, mx = 0, x, y;
  cin >> t;
  string s;
  while (t--) {
    cin >> n >> k >> s;
    sum = 0;
    bool h = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') h = false;
    }
    if (h) {
      if (n == k)
        cout << 1 << endl;
      else
        cout << (n + k) / (k + 1) << endl;
    } else {
      ans = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
          x = i;
          break;
        } else
          ans++;
      }
      sum += ans / (k + 1);
      ans = 0;
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
          y = i;
          break;
        } else
          ans++;
      }
      sum += ans / (k + 1);
      ans = 0;
      for (int i = x; i <= y; i++) {
        if (s[i] == '0')
          ans++;
        else {
          sum += (ans - k) / (k + 1);
          ans = 0;
        }
      }
      cout << sum << endl;
    }
  }
}
