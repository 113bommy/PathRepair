#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[101] = {0}, b[101] = {0};
  cin >> n >> m;
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      if (c == '*') {
        a[i]++;
        b[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) cout << i << " ";
  }
  for (int i = 0; i < m; i++) {
    if (b[i] == 1) cout << i << endl;
  }
  return 0;
}
