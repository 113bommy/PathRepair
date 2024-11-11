#include <bits/stdc++.h>
using namespace std;
const int n = 2e2 + 5;
int flats;
int luzes[n];
int resposta = 0;
int main() {
  cin >> flats;
  for (int i = 0; i < flats; i++) {
    cin >> luzes[i];
  }
  for (int i = 1; i < flats - 2; i++) {
    if (luzes[i - 1] == 1 && luzes[i] == 0 && luzes[i + 1] == 1) {
      luzes[i + 1] = 0;
      resposta = resposta + 1;
    }
  }
  cout << resposta << endl;
}
