#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  char pos[50];
  cin >> pos;
  while (t--) {
    for (int i = 0; i < n; i++) {
      if (pos[i] == 'B') {
        if ((i + 1) < n && pos[i + 1] == 'G') {
          char temp = pos[i];
          pos[i] = pos[i + 1];
          pos[i + 1] = temp;
          i++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << pos[i];
  }
  return 0;
}
