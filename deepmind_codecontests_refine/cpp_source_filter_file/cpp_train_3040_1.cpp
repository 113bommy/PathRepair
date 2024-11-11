#include <bits/stdc++.h>
using namespace std;
template <class T, class T2>
inline bool chkmax(T &x, const T2 &y) {
  return x < y ? x = y, 1 : 0;
}
template <class T, class T2>
inline bool chkmin(T &x, const T2 &y) {
  return x > y ? x = y, 1 : 0;
}
const long long mod = 1e9 + 7;
template <class T>
inline void fix(T &x) {
  if (x >= mod | x <= -mod) {
    x %= mod;
  }
  if (x < 0) {
    x += mod;
  }
}
const int MAX_N = 1e3 + 10;
char s[MAX_N];
vector<pair<int, int> > ans;
int n, k;
void reverse(int l, int r) {
  ans.emplace_back(l + 1, r + 1);
  for (; l < r; l++, r--) {
    swap(s[l], s[r]);
  }
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    ans.resize(0);
    for (int i = 0; i < k; i++) {
      for (int j = 2 * i;; j++) {
        if (s[j] == '(') {
          reverse(2 * i, j);
          break;
        }
      }
      for (int j = 2 * i + 1;; j++) {
        if (s[j] == ')') {
          reverse(2 * i + 1, j);
          break;
        }
      }
    }
    int up = 2 * k;
    int lft = (n - 2 * k) / 2;
    for (int i = 0; i < lft; i++) {
      for (int j = up; j < n; j++) {
        if (s[j] == '(') {
          reverse(up, j);
          up++;
          break;
        }
      }
    }
    cout << ans.size() << "\n";
    for (auto it : ans) {
      cout << it.first << " " << it.second << "\n";
    }
  }
  return 0;
}
