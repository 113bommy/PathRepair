#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a = '#';
  char b = '.';
  for (int i = 1; i <= m; i++) {
    if ((i / 2) % 2 == 0 && i % 2 == 0) {
      cout << "#";
      for (int i = 0; i < m - 1; i++) {
        cout << b;
      }
      cout << "\n";
    } else if ((i / 2) % 2 != 0 && i % 2 == 0) {
      for (int i = 0; i < m - 1; i++) {
        cout << b;
      }
      cout << "#";
      cout << "\n";
    } else {
      for (int i = 0; i < m; i++) {
        cout << a;
      }
      cout << "\n";
    }
  }
}
