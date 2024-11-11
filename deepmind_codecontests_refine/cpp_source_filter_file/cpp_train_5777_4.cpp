#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n1";
  } else if (n == 2) {
    cout << "1\n1";
  } else if (n == 3) {
    cout << "2\n1 3";
  } else if (n == 4) {
    cout << "3\n3 1 4 2";
  } else {
    cout << n << endl;
    int j = 0;
    for (int i = 1; i <= ceil(float(n) / float(2)); i++) {
      cout << 1 + j << " ";
      j += 2;
    }
    j = 0;
    for (int i = ceil(float(n) / float(2)) + 1; i <= n; i++) {
      cout << 2 + j << " ";
      j += 2;
    }
  }
}
