#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  char **led = new char *[y];
  for (int i = 0; i < y; ++i) led[i] = new char[x];
  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < x; ++j) cin >> led[i][j];
  }
  char **led2 = new char *[x];
  for (int i = 0; i < x; ++i) led2[i] = new char[y];
  for (int i = 0; i < y; i++)
    for (int j = 0; j < x; j++) led2[j][y - 1 - i] = led[i][j];
  delete[] led;
  char **led3 = new char *[x];
  for (int i = 0; i < x; ++i) led3[i] = new char[y];
  for (int i = 0; i < x; ++i)
    for (int j = 0; j < y; ++j) {
      led3[i][j] = led2[i][y - 1 - j];
    }
  delete[] led2;
  for (int i = 0; i < x; ++i) {
    for (int s = 0; s < 2; ++s) {
      for (int j = 0; j < y; ++j)
        for (int k = 0; k < 2; ++k) cout << led3[i][j];
      cout << endl;
    }
  }
}
