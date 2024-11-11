#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s, r;
  cin >> s >> r;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (flag) {
      int res = s[i] - '0';
      int red = s[i] - '0';
      if (res > 2 && red > 2) {
        flag = !flag;
      } else if (res > 2 && red <= 2) {
        cout << "NO" << endl;
        return;
      }
    } else {
      int res = s[i] - '0';
      int red = s[i] - '0';
      if (red > 2 && res > 2) {
        flag = !flag;
      } else if (red > 2 && res <= 2) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  if (flag == false) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  cin >> test;
  while (test--) solve();
  return 0;
}
