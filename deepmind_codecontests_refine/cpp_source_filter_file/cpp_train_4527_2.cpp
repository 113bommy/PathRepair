#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
long long n, x, y, a, b, c, d, sub;
string s;
vector<long long> temp;
vector<vector<long long>> A;
void inline solve() {
  cin >> n;
  for (int l = 0; l < n; l += 1) {
    cin >> x >> y;
    b = x % 10;
    x /= 10;
    a = x % 10;
    c = y % 10;
    y /= 10;
    d = y % 10;
    if (l != n - 1) cin >> s;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    temp.push_back(d);
    bool ok = true;
    for (int i = 0; i < A.size(); i += 1) {
      ok = true;
      int k = 0;
      int y = 4;
      while (y--) {
        sub = 0;
        int o = 0;
        for (int j = k; j < k + 4; j += 1) {
          sub = sub + abs(A[i][o] - temp[j % n]);
          o++;
        }
        if (sub == 0) {
          ok = false;
          break;
        }
        k++;
      }
      if (!ok) break;
    }
    if (ok) A.push_back(temp);
    temp.clear();
  }
  cout << A.size() << endl;
}
int main() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
}
