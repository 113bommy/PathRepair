#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> s;
  char current = s[0];
  size_t s_f = 0;
  size_t f_s = 0;
  for (int i = 1; i < n; i++) {
    if (current != s[i]) {
      if (current == 'S') {
        s_f++;
      } else {
        f_s++;
      }
      current = s[i];
    }
  }
  if (s_f > f_s) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
