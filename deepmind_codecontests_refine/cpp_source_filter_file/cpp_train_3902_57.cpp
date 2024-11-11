#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int toggle = m - 1;
  for (int i = 0; i <= n; i++) {
    int count = 1;
    for (int j = 0; j < m; j++) {
      if (i % 2 != 0)
        cout << '#';
      else {
        if (j == toggle && count == 1) {
          count++;
          cout << '#';
          toggle = (toggle == 0) ? m - 1 : 0;
        } else
          cout << ".";
      }
    }
    cout << endl;
  }
}
