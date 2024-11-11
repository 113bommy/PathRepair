#include <bits/stdc++.h>
using namespace std;
int vis[101];
char arr[150][150];
int main() {
  int f = 1, k = 1;
  string s;
  char ch, vh;
  int a, b = 0;
  cin >> a;
  for (int i = 0; i < a; i++) {
    f = k;
    for (int j = 0; j < a; j++) {
      if (f == 1) {
        arr[i][j] = 'c';
        b++;
        f = -1;
      } else {
        arr[i][j] = '.';
        f = 1;
      }
    }
    k = -1 * k;
  }
  cout << b << endl;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
  return 0;
}
