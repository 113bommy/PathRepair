#include <bits/stdc++.h>
using namespace std;
int main() {
  char data[200];
  int val;
  bool est = false;
  cin >> val;
  for (int i = 0; i < val; i++) cin >> data[i];
  for (int i = 1; i < val; i++)
    for (int j = 0; j < val; j++) {
      int cont = 1;
      for (int k = 0; k < val; k += i) {
        if (data[j + k] == '*')
          cont++;
        else
          cont = 1;
        if (cont >= 5) est = true;
      }
    }
  cout << (est ? "yes" : "no") << endl;
}
