#include <bits/stdc++.h>
using namespace std;
int main() {
  char array[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[',
                  ']', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
                  'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
  string x;
  char direction;
  cin >> direction;
  cin >> x;
  int len = x.length();
  if (direction == 'L') {
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < 32; j++) {
        if (x[i] == array[j]) {
          x[i] = array[j + 1];
          break;
        }
      }
    }
  } else {
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < 32; j++) {
        if (x[i] == array[j]) {
          x[i] = array[j - 1];
          break;
        }
      }
    }
  }
  cout << x << endl;
}
