#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  int n, d;
  cin >> n >> d;
  cin >> s;
  int position = 0;
  int jumps = 0;
  bool k = 1;
  while (position != n - 1) {
    int f = position;
    for (int i = d + position; i > position; i--) {
      if (s[i] == '1') {
        position = i;
        break;
      } else if (i == f + 1) {
        cout << -1;
        return 0;
      }
    }
    jumps++;
  }
  if (position >= n - 1)
    cout << jumps;
  else
    cout << -1;
  return 0;
}
