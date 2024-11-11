#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0, ans = 0;
  string s;
  bool cek = 0;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (cek == 0) {
      if (s[i] == 'x') {
        cek = 1;
        cnt++;
      }
    } else {
      if (cnt >= 3) {
        ans++;
      }
      if (s[i] == 'x') {
        cnt++;
      } else {
        cek = 0;
        cnt = 0;
      }
    }
  }
  if (cnt >= 2 && s[n - 1] == 'x') ans++;
  cout << ans << "\n";
}
