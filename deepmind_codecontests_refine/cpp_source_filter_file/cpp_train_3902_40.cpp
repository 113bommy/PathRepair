#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i % 2 == 1) {
        if (i % 4 == 1)
          if (j == n - 1)
            cout << '#';
          else
            cout << '.';
        else if (j == 0)
          cout << '#';
        else
          cout << '.';
      } else
        cout << '#';
    }
    cout << endl;
  }
}
