#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n <= 3) {
    cout << "NO" << endl;
    return 0;
  } else
    cout << "YES" << endl;
  if (n == 4) {
    cout << 4 << " * " << 3 << " = " << 12 << "\n"
         << 1 << " * " << 2 << " = " << 2 << "\n"
         << 12 << " * " << 2 << " = " << 24 << endl;
    return 0;
  }
  int val = n - 6;
  int dem = 0;
  if (val % 2 == 0) {
    bool k = true;
    for (int i = n; i > 6; i -= 2) {
      cout << i << " - " << i - 1 << " = " << 1 << endl;
      dem++;
    }
    for (int i = 0; i < dem; i++) cout << 6 << " * " << 1 << " = " << 6 << endl;
    cout << 6 << " - " << 3 << " = " << 3 << "\n"
         << 5 << " - " << 2 << " = " << 3 << "\n"
         << 3 << " - " << 1 << " = " << 2 << "\n"
         << 4 << " * " << 3 << " = " << 12 << "\n"
         << 12 << " * " << 2 << " = " << 24 << endl;
  } else {
    for (int i = n; i >= 6; i -= 2) {
      cout << i << " - " << i - 1 << " = " << 1 << endl;
      dem++;
    }
    for (int i = 0; i < dem; i++) cout << 5 << " * " << 1 << " = " << 5 << endl;
    cout << 5 << " - " << 2 << " = " << 3 << "\n"
         << 3 << " - " << 1 << " = " << 2 << "\n"
         << 4 << " * " << 3 << " = " << 12 << "\n"
         << 12 << " * " << 2 << " = " << 24 << endl;
  }
  return 0;
}
