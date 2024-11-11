#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 1, h = 0;
  char x[1500];
  cin >> x;
  cout << x[0];
  h = 0;
  while (x[i] != 0) {
    if (x[i] == '<') {
      if (x[i + 1] == '/') {
        h--;
      } else {
        h++;
      }
    }
    cout << x[i];
    if (x[i] == '>') {
      cout << "\n";
      if (x[i + 2] == '/') {
        for (int j = 0; j < h * 2; j++) {
          cout << " ";
        }
      } else {
        for (int j = 0; j < (h + 1) * 2; j++) {
          cout << " ";
        }
      }
    }
    i++;
  }
  return 0;
}
