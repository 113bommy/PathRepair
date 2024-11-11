#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c = 0;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    if (i % 2 != 0) {
      c++;
      if (c % 2 != 0)
        for (int j = 0; j < b; j++) {
          if (j == b - 1)
            cout << "#";
          else
            cout << ".";
        }
      else
        for (int j = 0; j < b; j++) {
          if (j == 0)
            cout << "#";
          else
            cout << ".";
        }
    } else {
      for (int j = 0; j < b; j++) cout << "#";
    }
    cout << endl;
  }
}
