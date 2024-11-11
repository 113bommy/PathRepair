#include <bits/stdc++.h>
using namespace std;
int main() {
  string aux;
  cin >> aux;
  int flag_Invalid_Input = 0;
  int memo[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
  int counter = 0;
  int len = aux.size();
  int i, j;
  for (i = 0; i < len; i++) {
    if (aux[i] > '1') {
      for (j = 0; j < len - i; j++) {
        counter += memo[j];
      }
      break;
    }
    if (aux[i] == '1') {
      counter += memo[len - i - 1];
    }
  }
  cout << counter;
}
