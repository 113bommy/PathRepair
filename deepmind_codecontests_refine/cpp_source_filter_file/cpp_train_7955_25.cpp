#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 6) {
    cout << "1 2 2" << endl;
    cout << "2 5 1" << endl;
    cout << "4 5 1" << endl;
    cout << "5 6 3" << endl;
    cout << "3 6 1" << endl;
    cout << "1 3" << endl;
    cout << "2 3" << endl;
    cout << "4 3" << endl;
  } else {
    cout << "1 2 1" << endl;
    cout << "2 " << n << " 1" << endl;
    int i = 3, j = n - 1;
    for (; i + 1 <= j; i++, j--) {
      cout << i << " " << j << " " << 1 << endl;
      cout << j << " " << j + 1 << " " << i - 1 << endl;
    }
    if (i == j) cout << j << " " << j + 1 << " " << 1 << endl;
    int ind = 3;
    for (int k = 0; k < n / 2; k++) {
      if (k % 2 == 0) {
        cout << "1 " << ind << endl;
      } else {
        cout << "2 " << ind << endl;
        ind++;
      }
    }
  }
}
