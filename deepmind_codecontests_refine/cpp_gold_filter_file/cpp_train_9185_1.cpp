#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int inf = 1e9;
const int mo = 998244353;
int a[N], b[N];
void trans(int i) {
  swap(a[i], a[i + 2]);
  swap(a[i + 1], a[i + 2]);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> ans;
    int n;
    cin >> n;
    for (auto i = (1); i <= (n); ++i) cin >> a[i];
    for (auto i = (1); i <= (n); ++i) b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int mepos = -1;
    for (auto i = (2); i <= (n); ++i) {
      if (b[i] == b[i - 1]) mepos = i;
    }
    bool ok = 1;
    for (auto i = (1); i <= (n); ++i) {
      int now = b[i];
      for (auto j = (i); j <= (n); ++j) {
        if (a[j] == now) {
          for (int k = j - 2; k >= i; k -= 2) {
            ans.push_back(k);
            trans(k);
          }
        }
      }
      if (a[i] != now) {
        if (i + 2 <= n) {
          ans.push_back(i);
          trans(i);
          ans.push_back(i);
          trans(i);
        } else
          ok = 0;
      }
      if (i == mepos) {
        int inv = 0;
        for (auto j = (i + 2); j <= (n); ++j) {
          for (auto k = (i + 1); k <= (j - 1); ++k) {
            if (a[k] > a[j]) inv++;
          }
        }
        if (inv & 1) {
          trans(i - 1);
          trans(i - 1);
          trans(i);
          trans(i);
          ans.push_back(i - 1);
          ans.push_back(i - 1);
          ans.push_back(i);
          ans.push_back(i);
        }
      }
    }
    if (!ok && a[n - 2] == a[n]) {
      ans.push_back(n - 2);
      trans(n - 2);
      ok = 1;
    }
    if (!ok) {
      cout << "-1\n";
    } else {
      cout << ans.size() << endl;
      for (auto x : ans) cout << x << " ";
      cout << endl;
    }
  }
  return 0;
}
