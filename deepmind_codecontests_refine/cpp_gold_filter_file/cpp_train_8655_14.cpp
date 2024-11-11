#include <bits/stdc++.h>
using namespace std;
int main() {
  int nbr_of_a = 0;
  string a;
  int taille;
  cin >> a;
  taille = a.size();
  for (int k = 0; k < taille; k++) {
    if (a[k] == 'a') {
      nbr_of_a++;
    }
  }
  int result;
  if (nbr_of_a > taille / 2) {
    cout << a.size();
  } else {
    result = (2 * nbr_of_a - 1);
    cout << result;
  }
  return 0;
}
