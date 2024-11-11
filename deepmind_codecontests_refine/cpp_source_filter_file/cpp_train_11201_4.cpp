#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, i, c = 0, d = 0;
  cin >> x;
  int n[x], m[x];
  for (i = 0; i < x; i++) {
    cin >> n[i] >> m[i];
  }
  if (n[0] != m[0]) c = 1;
  for (i = 1; i < x; i++) {
    if (c == 1) break;
    if (n[i] == m[i]) {
      if (n[i - 1] < n[i]) {
        d = 1;
      }
    } else {
      c = 1;
      break;
    }
  }
  if (d == 1)
    cout << "unrated\n";
  else if (c == 1)
    cout << "rated\n";
  else
    cout << "maybe\n";
}
