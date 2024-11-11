#include <bits/stdc++.h>
using namespace std;
const int N = 18;
int cnt[1005], cnt1[1005];
pair<int, int> p[10000];
vector<int> v;
int main() {
  bool ok = 0;
  int res1 = 0, res2 = 0, res3 = 0, res4 = 0, res5 = 0, kq = 1e9, sl1 = 0,
      sl2 = 0;
  int n, m, k = 1e3, l = 0, d, pre = 0, t;
  string x, y;
  string s;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1) {
      for (int j = 1; j <= m; ++j) {
        cout << '#';
      }
      cout << "\n";
      continue;
    }
    if (i % 4 == 0) {
      cout << '#';
      for (int j = 2; j <= m; ++j) {
        cout << '.';
      }
      cout << '\n';
      continue;
    }
    if (i % 2 == 0) {
      for (int j = 1; j <= m - 1; ++j) {
        cout << '.';
      }
      cout << '#';
      cout << '\n';
      continue;
    }
  }
}
