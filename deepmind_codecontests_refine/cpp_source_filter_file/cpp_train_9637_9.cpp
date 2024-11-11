#include <bits/stdc++.h>
using namespace std;
void optimise() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  int a, x, y, ct = 0;
  char s[4] = {};
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 4; j++) s[j] = '0' + i;
    cout << s << endl;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      a = i;
      break;
    }
  }
  char foo[4] = {};
  char ans[4] = {};
  for (int i = 0; (i < 10) && (ct < 4); i++) {
    for (int pos = 0; pos < 4; pos++) {
      for (int j = 0; j < 4; j++) foo[j] = a + '0';
      foo[pos] = i + '0';
      cout << foo << endl;
      cin >> x >> y;
      if (x == 1) {
        ct++;
        ans[pos] = i + '0';
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
