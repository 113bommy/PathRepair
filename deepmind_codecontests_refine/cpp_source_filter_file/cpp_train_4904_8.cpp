#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a < 3)
    cout << "No";
  else {
    cout << "Yes" << endl;
    int b = a / 2, c = a / 2 + a % 2;
    cout << a << " ";
    for (int i = 2; i <= a; i += 2) cout << i << " ";
    cout << endl << c << " ";
    for (int i = 1; i <= a; i += 2) cout << i << " ";
  }
}
