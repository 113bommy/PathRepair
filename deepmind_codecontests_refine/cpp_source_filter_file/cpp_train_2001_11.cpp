#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> col(n);
  vector<int> last(26, -1);
  for (int i = n - 1; i >= 0; --i) {
    int c = s[i] - 'a';
    int mx = -1;
    for (int i = 0; i < c; ++i) mx = max(mx, last[i]);
    col[i] = mx + 1;
    last[c] = mx + 1;
  }
  cout << *max_element(col.begin(), col.end()) << endl;
  for (int i = 0; i < n; ++i) cout << col[i] + 1 << " ";
  cout << endl;
}
int main() {
  int t = 1;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
