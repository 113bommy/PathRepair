#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int arr[a][a];
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      arr[i][j] = 0;
      if (i == j) {
        cout << b << " ";
      }
      cout << 0 << " ";
    }
    cout << endl;
  }
}
