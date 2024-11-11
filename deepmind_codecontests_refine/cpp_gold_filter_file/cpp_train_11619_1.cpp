#include <bits/stdc++.h>
using namespace std;
int a[10001], b[10001];
int main() {
  int n, m;
  ;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int L, R, x, cnt = 1;
  vector<string> ans;
  for (int i = 1; i <= m; ++i) {
    cin >> L >> R >> x;
    if (x < L || x > R) {
      ans.push_back("Yes");
    } else {
      for (int j = L; j <= R; ++j) {
        b[a[j]] = cnt;
      }
      int h = x - L + 1, q = 0;
      for (int k = 1; k <= 10000; ++k) {
        if (b[k] == cnt) q++;
        if (h == q) {
          if (k == a[x])
            ans.push_back("Yes");
          else
            ans.push_back("No");
          break;
        }
      }
    }
    ++cnt;
  }
  for (vector<string>::iterator it = ans.begin(); it != ans.end(); ++it)
    cout << *it << "\n";
  return 0;
}
