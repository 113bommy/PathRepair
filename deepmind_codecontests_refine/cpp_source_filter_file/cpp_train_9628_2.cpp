#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k * 2 >= n * n + 1) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  for (int I = 0; I < n; I++) {
    for (int j = 0; j < n; j++) {
      if (((I % 2 == 0 && j % 2 == 0) || (I % 2 == 1 && j % 2 == 1)) && k > 0) {
        cout << 'L';
        k--;
      } else
        cout << 'S';
    }
    cout << endl;
  }
  return 0;
}
