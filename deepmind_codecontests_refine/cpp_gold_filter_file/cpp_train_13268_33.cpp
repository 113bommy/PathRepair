#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int ar[a * 2];
  int aa = 0;
  for (int AsAlwaysI = 0; AsAlwaysI < a * 2; AsAlwaysI++) {
    int d;
    cin >> d;
    ar[AsAlwaysI] = d;
  }
  for (int AsAlwaysI = 0; AsAlwaysI < a * 2; AsAlwaysI++) {
    AsAlwaysI++;
    if (ar[AsAlwaysI] - ar[AsAlwaysI - 1] >= 2) aa++;
  }
  cout << endl << aa;
}
