#include <bits/stdc++.h>
using namespace std;
int k, n, r;
void bus_shape() {
  cin >> n;
  cout << "+------------------------+" << endl;
  for (int i = 1; i <= 4; i++) {
    k = n;
    cout << "|";
    for (int j = 1; j <= 11; j++) {
      if (i == 3) {
        if (k)
          cout << "O.....................", n--;
        else
          cout << "#.....................";
        j = 12;
      } else {
        if (j == 1) {
          if (k > 0)
            cout << "O.", k -= (5 - i), n--;
          else
            cout << "#.";
        } else {
          if (k > 0)
            cout << "O.", k -= (4 - i + (i == 4)), n--;
          else
            cout << "#.";
        }
      }
    }
    if (i == 1)
      cout << "|D|)" << endl;
    else if (i == 2)
      cout << "|.|" << endl;
    else if (i == 3)
      cout << "..|" << endl;
    else
      cout << "|.|)" << endl;
  }
  cout << "+------------------------+";
}
int main() { bus_shape(); }
