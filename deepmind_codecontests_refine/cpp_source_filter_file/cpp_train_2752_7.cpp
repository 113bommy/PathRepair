#include <bits/stdc++.h>
using namespace std;
const int size = 100000;
int a[size];
int main() {
  int ents, pce = 0, unt = 0;
  cin >> ents;
  for (int i = 0; i < ents; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < ents; i++) {
    if (a[i] == -1) {
      if (pce > 0)
        pce = 0;
      else
        unt++;
    } else {
      pce += a[i];
    }
  }
  cout << unt;
  return 0;
}
