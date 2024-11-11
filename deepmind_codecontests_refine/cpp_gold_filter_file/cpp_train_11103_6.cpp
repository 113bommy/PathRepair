#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, i, x;
  cin >> n;
  string s;
  cin >> s;
  x = n;
  for (i = 0; i < n; i++) {
    if (s[i] == 'R' && s[i + 1] == 'U') {
      x--;
      i++;
    } else if (s[i] == 'U' && s[i + 1] == 'R') {
      x--;
      i++;
    }
  }
  cout << x << '\n';
}
