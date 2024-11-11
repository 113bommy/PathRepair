#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    string s;
    cin >> s;
    int a[3];
    int cnt = 0;
    for (int i = 0; i < 3; i++) a[i] = 0;
    for (int i = 0; i < s.length(); i++) {
      if ((s[i] - 48) % 3 == 0) {
        cnt++;
        a[0] = a[1] = a[2] = 0;
      } else {
        if (a[3 - (s[i] - 48) % 48] == 1) {
          cnt++;
          a[0] = a[1] = a[2] = 0;
        } else if (a[(s[i] - 48) % 48] == 1)
          a[3 - (s[i] - 48) % 48] = 1;
        else
          a[(s[i] - 48) % 3] = 1;
      }
    }
    cout << cnt << endl;
  }
}
