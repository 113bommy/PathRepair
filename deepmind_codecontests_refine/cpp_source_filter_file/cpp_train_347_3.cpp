#include <bits/stdc++.h>
using namespace std;
bool orden(int a, int b) {
  if (a == b)
    return true;
  else
    return false;
}
int main() {
  int arreglo[100000], n, x;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arreglo[i];
  if (n < 3)
    cout << "-1" << endl;
  else {
    for (x = 0; (x < n - 1) && orden(arreglo[x], arreglo[x + 1]); x++)
      ;
    if (x == n - 1)
      cout << "-1" << endl;
    else if (x == 0) {
      if (n == 3) {
        if (arreglo[0] > arreglo[2]) {
          if (arreglo[0] == arreglo[2])
            cout << "-1" << endl;
          else if (arreglo[0] < arreglo[2])
            cout << "1 3" << endl;
          else
            cout << "1 2" << endl;
        } else {
          if (arreglo[0] == arreglo[2])
            cout << "-1" << endl;
          else if (arreglo[0] > arreglo[2])
            cout << "1 3" << endl;
          else
            cout << "1 2" << endl;
        }
      } else if (arreglo[1] == arreglo[2])
        cout << "1 2" << endl;
      else
        cout << "2 3" << endl;
    } else {
      cout << x + 1 << " " << x + 2 << endl;
    }
  }
  return 0;
}
