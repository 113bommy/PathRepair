#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  int n, p;
  while (cin >> n >> p >> s) {
    if (n == 1) {
      cout << "No\n";
      return 0;
    }
    int len = n - p;
    for (int i = 0; i < len; i++) {
      if (i + p == n) {
        cout << "No\n";
        return 0;
      }
      if (s[i] == '.') {
        if (s[i + p] == '.')
          s[i] = '1', s[i + p] = '0';
        else {
          if (s[i + p] == '0')
            s[i] = '1';
          else
            s[i] = '0';
        }
        break;
      } else if (s[i + p] == '.') {
        if (s[i] == '1')
          s[i + p] = '0';
        else
          s[i + p] = '1';
        break;
      } else if (s[i] != s[i + p])
        break;
      else if (i == len - 1) {
        cout << "No\n";
        return 0;
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '.') s[i] = '0';
    }
    cout << s << endl;
  }
}
