#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int y = 0;
  int s, v, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> v >> t;
    if (s == v) {
      if (s == 1) {
        y++;
      } else {
      }
    } else {
      if (s == t) {
        if (s == 1) {
          y++;
        } else {
        }
      } else {
        if (v == t) {
          if (v == 1) {
            y++;
          } else {
          }
        } else {
        }
      }
    }
    cout << y;
  }
}
