#include <bits/stdc++.h>
using namespace std;
long long i, n, j, k;
void vao() { cin >> n; }
void xuly() {
  if (i % 2 == 1)
    cout << "-1" << endl;
  else {
    for (i = 1; i <= n; i++)
      if (i % 4 == 1 || i % 4 == 2) {
        for (j = 1; j <= n; j++) {
          for (k = 1; k <= n / 2; k++)
            if (j % 2 == 1) {
              if (k % 2 == 1)
                cout << "bb";
              else
                cout << "ww";
            } else {
              if (k % 2 == 1)
                cout << "ww";
              else
                cout << "bb";
            }
          cout << endl;
        }
        cout << endl;
      } else {
        for (j = 1; j <= n; j++) {
          for (k = 1; k <= n / 2; k++)
            if (j % 2 == 1) {
              if (k % 2 == 1)
                cout << "ww";
              else
                cout << "bb";
            } else {
              if (k % 2 == 1)
                cout << "bb";
              else
                cout << "ww";
            }
          cout << endl;
        }
        cout << endl;
      }
  }
}
void ra() {}
int main() {
  vao();
  xuly();
  ra();
}
