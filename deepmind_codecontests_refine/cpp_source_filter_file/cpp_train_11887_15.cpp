#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[2 * n];
  if (n % 2 == 0)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    int i = 0;
    int od = 1;
    while (i < n) {
      ar[i] = od;
      i += 2;
      od += 4;
    }
    od -= 2 + 4;
    while (i < 2 * n) {
      ar[i] = od;
      i += 2;
      od -= 4;
    }
    int j = n;
    od = 2;
    while (j < 2 * n) {
      ar[j] = od;
      j += 2;
      od += 4;
    }
    od -= 2 + 4;
    j = 1;
    while (j < n) {
      ar[j] = od;
      j += 2;
      od -= 4;
    }
  }
  for (int i = 0; i < 2 * n; i++) cout << ar[i] << " ";
}
