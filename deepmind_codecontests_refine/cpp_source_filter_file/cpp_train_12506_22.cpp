#include <bits/stdc++.h>
using namespace std;
void fastIo() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIo();
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
      cout << "NO" << endl;
    } else if (n == 2) {
      if (s[0] <= s[1])
        cout << "NO" << endl;
      else {
        cout << "YES" << endl;
        cout << "2" << endl;
        cout << s[0] << " " << s[1] << endl;
      }
    } else {
      cout << "YES" << endl;
      cout << "2" << endl;
      cout << s[0] << " ";
      for (int i = 1; i < n; i++) cout << s[i];
      cout << endl;
    }
  }
  return 0;
}
