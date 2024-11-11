#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a = 0, b = 0;
  int l = -2, r = -2;
  for (int i = 0; i < n; i++) {
    a = 0;
    b = 0;
    for (int j = i; j < n; j++) {
      if (s[j] == 'a')
        a++;
      else if (s[j] == 'b')
        b++;
      if (a == b) {
        l = i;
        r = j;
        break;
      }
    }
  }
  cout << l + 1 << " " << r + 1 << "\n";
}
