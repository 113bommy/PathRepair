#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, l, r;
  string str;
  char c1, c2;
  cin >> n >> m;
  cin >> str;
  for (__typeof(m) j = 0; j < m; j++) {
    cin >> l >> r >> c1 >> c2;
    l--;
    r--;
    for (int i = l; i <= r; i++) {
      if (str[i] == c1) str[i] = c2;
    }
  }
  cout << str << endl;
  return 0;
}
