#include <bits/stdc++.h>
using namespace std;
int n, q;
string s, t;
void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> q;
  while (q--) {
    cin >> n;
    cin >> s >> t;
    string a = s, b = t;
    s = " " + s;
    t = " " + t;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a != b) {
      cout << -1;
      continue;
    }
    int k, res = INT_MAX;
    for (int i = 1; i <= n; i++) {
      k = i;
      for (int j = 1; j <= n; j++) {
        if (s[j] == t[k] && k <= n) k++;
      }
      res = min(res, n - k + i);
    }
    cout << res << "\n";
  }
}
int main() {
  input();
  return 0;
}
