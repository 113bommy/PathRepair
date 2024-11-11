#include <bits/stdc++.h>
using namespace std;
int eve(long long int x) {
  if (x % 2 == 0) return 1;
  return 0;
}
void solve() {
  int i, j, flag = 1;
  string s;
  for (i = 0; i < 1; ++i) {
    cin >> s;
    if (flag == 1) {
      for (j = 1; j < 8; ++j) {
        if (s[j - 1] == s[j]) {
          flag = 0;
          break;
        }
      }
      if (s[7] == s[0]) flag = 0;
    }
  }
  if (flag == 0)
    cout << "NO";
  else
    cout << "YES";
  cout << endl;
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
}
