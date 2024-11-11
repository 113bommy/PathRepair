#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, ch = 1, result = 0;
  int mas[4];
  cin >> mas[0] >> mas[1] >> mas[2] >> mas[3];
  for (int i = 0; i < 4; i++) {
    a = i;
    for (int j = 0; j < 4; j++) {
      if (a != j) {
        b = j;
        for (int k = 0; k < 4; k++) {
          if (a != k && b != k) {
            c = k;
            cerr << ch << "!" << mas[a] << mas[b] << mas[c] << endl;
            ch++;
            if (mas[a] + mas[b] > mas[c] && mas[b] + mas[c] > mas[a] &&
                mas[a] + mas[c] > mas[b]) {
              cout << "TRIANGLE";
              return 0;
            } else {
              if (mas[a] == (mas[a] + mas[b] + mas[c]) / 2.0 ||
                  mas[c] == (mas[a] + mas[b] + mas[c]) / 2.0 ||
                  mas[c] == (mas[a] + mas[b] + mas[c]) / 2.0) {
                result = 1;
              }
            }
          }
        }
      }
    }
  }
  if (result == 1)
    cout << "SIGMENT";
  else
    cout << "IMPOSSIBLE";
}
