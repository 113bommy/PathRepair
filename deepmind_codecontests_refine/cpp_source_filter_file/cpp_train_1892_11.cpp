#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("fast-math")
using namespace std;
const int DEBUG = 0;
mt19937 gen(
    (unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
#pragma comment(linker, "/STACK:16777216")
void solve() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  vector<int> x1(26, 1000000000), x2(26, -1), y1(26, 1000000000), y2(26, -1);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '.') continue;
      int k = (a[i][j] - 'a');
      x1[k] = min(x1[k], j);
      x2[k] = max(x2[k], j);
      y1[k] = min(y1[k], i);
      y2[k] = max(y2[k], i);
    }
  }
  int ok = 1;
  int last = -1;
  int last_ch = -1;
  for (int i = 0; i < 26; i++) {
    if (x1[i] != 1000000000) last_ch = i;
  }
  for (int i = 0; i < 26; i++) {
    if (x1[i] == 1000000000) {
      if (i <= last_ch && last_ch != -1) {
        x1[i] = x1[last_ch];
        x2[i] = x2[last_ch];
        y1[i] = y1[last_ch];
        y2[i] = y2[last_ch];
      }
      continue;
    }
    last = i;
    if (x1[i] != x2[i] && y1[i] == y2[i])
      ;
    else if (x1[i] == x2[i] && y1[i] != y2[i])
      ;
    else if (x1[i] == x2[i] && y1[i] == y2[i])
      ;
    else
      ok = 0;
  }
  if (!ok) {
    cout << "NO";
    return;
  }
  vector<string> b(h, string(w, '.'));
  int cnt = 0;
  for (int k = 0; k < 26; k++) {
    if (x1[k] == 1000000000) continue;
    ++cnt;
    for (int i = y1[k]; i <= y2[k]; i++)
      for (int j = x1[k]; j <= x2[k]; j++) b[i][j] = char('a' + k);
  }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (a[i][j] != b[i][j]) ok = 0;
  if (!ok) {
    cout << "NO";
    return;
  }
  cout << "YES\n";
  cout << cnt << "\n";
  for (int i = 0; i < cnt; i++) {
    cout << y1[i] + 1 << " " << x1[i] + 1 << " " << y2[i] + 1 << " "
         << x2[i] + 1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(cout.fixed);
  cout.precision(12);
  auto START_TIME = chrono::high_resolution_clock::now();
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
