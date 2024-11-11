#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int crystal_size;
  cin >> crystal_size;
  int i, j;
  int stars = crystal_size / 2;
  for (i = 0; i < crystal_size; i++) {
    for (j = 0; j < stars; j++) cout << "*";
    for (j = 0; j <= crystal_size - 2 * stars; j++) cout << "D";
    for (j = 0; j < stars; j++) cout << "*";
    if (i < crystal_size / 2)
      stars--;
    else
      stars++;
    cout << endl;
  }
}
