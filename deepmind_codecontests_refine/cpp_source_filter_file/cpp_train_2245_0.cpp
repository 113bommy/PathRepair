#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, t;
  bool pos[101] = {false}, more, map[101] = {false};
  string s;
  cin >> n >> k;
  char ch;
  for (i = 0; i < n; i++) {
    cin >> ch;
    if (ch == 'G') pos[i] = true;
    if (ch == 'T') {
      t = i;
      map[i] = true;
    }
    if (ch == '.') map[i] = true;
  }
  more = true;
  while (more == true) {
    more = false;
    for (i = 0; i < n; i++) {
      if (pos[i] == true) {
        if (i - k >= 0 && pos[i - k] == false && map[i] == true) {
          pos[i - k] = true;
          more = true;
        }
        if (i + k < n && pos[i + k] == false && map[i] == true) {
          pos[i + k] = true;
        }
      }
    }
  }
  if (pos[t] == true)
    cout << "YES";
  else
    cout << "NO";
}
