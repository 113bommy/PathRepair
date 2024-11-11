#include <bits/stdc++.h>
using namespace std;
vector<string> mas;
int n, m;
void input() {
  cin >> n >> m;
  mas.clear();
  mas.resize(n);
  for (int i = 0; i < n; ++i) cin >> mas[i];
}
void solve() {
  string ans = mas[0];
  for (int i = 0; i < m; ++i) {
    char save = ans[i];
    for (char d = 'a'; d <= 'z'; d++) {
      ans[i] = d;
      bool f = 1;
      for (int j = 0; j < n; ++j) {
        int err = 0;
        for (int c = 0; c < m; ++c) {
          if (ans[c] != mas[j][c]) err++;
        }
        if (err > 1) {
          f = 0;
          break;
        }
      }
      if (f) {
        cout << ans << '\n';
        return;
      }
    }
    ans[i] = save;
  }
  cout << "-1\n";
}
int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    input();
    solve();
  }
  return 0;
}
