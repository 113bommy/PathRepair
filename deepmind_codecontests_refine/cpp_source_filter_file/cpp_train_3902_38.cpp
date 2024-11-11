#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int x = 0;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if (i % 2 == 0)
        cout << "#";
      else {
        if (j != 0 && j + 1 != b)
          cout << ".";
        else {
          if (x == 0 || x == 3)
            cout << ".";
          else
            cout << "#";
          x++;
          if (x == 3) x == 0;
        }
      }
    }
    cout << "\n";
  }
}
