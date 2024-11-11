#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char a[N][N];
int mark[N];
int n, m;
vector<int> l;
vector<int> r;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> (a[i] + 1);
  l.push_back(1);
  r.push_back(n);
  for (int c = 1; c <= m; ++c) {
    vector<int> nl;
    vector<int> nr;
    for (int j = 0; j < int(l.size()); ++j) {
      for (int i = l[j]; i < r[j]; ++i)
        if (a[i][c] > a[i + 1][c]) {
          mark[c] = 1;
          break;
        }
    }
    if (mark[c] == 0) {
      for (int j = 0; j < int(l.size()); ++j) {
        int last = l[j];
        for (int i = l[j] + 1; i <= r[j]; ++i)
          if (a[i][c] != a[i - 1][c]) {
            nl.push_back(last);
            nr.push_back(i - 1);
            last = i;
          }
        nl.push_back(last);
        nr.push_back(r[j]);
      }
      l = nl;
      r = nr;
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i)
    if (mark[i]) ++ans;
  cout << ans << '\n';
}
