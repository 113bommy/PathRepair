#include <bits/stdc++.h>
using namespace std;
int n;
bool vos[100];
bool soh[100];
int ok = 0;
int ans = 0;
void clea() {
  for (int i = 0; i < 100; i++) vos[i] = 0;
}
int main() {
  cin >> n;
  for (int r = 0; r < n; r++) {
    string com, q;
    cin >> com >> q;
    if (com == "!") {
      clea();
      for (int i = 0; q[i]; i++) {
        int t = q[i] - 'a';
        vos[t] = 1;
      }
      for (int i = 0; i < 26; i++) {
        if (vos[i] == 0) soh[i] = 1;
      }
      if (ok == 1) ans++;
    }
    if (com == ".") {
      for (int i = 0; q[i]; i++) {
        int t = q[i] - 'a';
        soh[t] = 1;
      }
    }
    if (com == "?") {
      int t = q[0] - 'a';
      if (t == 1 && ok == 1)
        ans++;
      else
        soh[t] = 1;
    }
    int y = 0;
    for (int i = 0; i < 26; i++)
      if (soh[i] == 0) y++;
    if (y == 1) ok = 1;
  }
  cout << ans << endl;
}
