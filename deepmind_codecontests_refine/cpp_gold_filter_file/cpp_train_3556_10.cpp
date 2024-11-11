#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, i, j, sortt, cart, tt;
  char c;
  cin >> num >> sortt;
  int arr[num][sortt];
  i = 0;
  while (i < num) {
    j = 0;
    while (j < sortt) {
      cin >> c;
      if (c == 'P') {
        arr[i][j++] = 0;
      } else if (c == 'W') {
        arr[i][j++] = 1;
      } else {
        arr[i][j++] = -1;
      }
    }
    i++;
  }
  i = 0;
  cart = 0;
  while (i < num) {
    j = 0;
    while (j < sortt) {
      if (arr[i][j] == 0) {
        if (i - 1 >= 0 && arr[i - 1][j] == 1) {
          cart++;
          arr[i - 1][j] = -1;
        } else if (i + 1 < num && arr[i + 1][j] == 1) {
          cart++;
          arr[i + 1][j] = -1;
        } else if (j - 1 >= 0 && arr[i][j - 1] == 1) {
          cart++;
          arr[i][j - 1] = -1;
        } else if (j + 1 < sortt && arr[i][j + 1] == 1) {
          cart++;
          arr[i][j + 1] = -1;
        }
      }
      j++;
    }
    i++;
  }
  cout << cart;
  return 0;
}
