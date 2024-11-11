#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    char str[m];
    for (int i = 0; i < m; i++) {
      cin >> str[i];
      if (str[i] == 'C' || str[i] == 'M' || str[i] == 'Y') {
        cout << "#Color";
        return 0;
      }
    }
  }
  cout << "#Black&White";
  return 0;
}
