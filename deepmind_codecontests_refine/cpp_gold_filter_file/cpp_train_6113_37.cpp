#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, p;
  cin >> c >> p;
  int arr[c], arrp[p];
  for (int i = 0; i < c; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < p; i++) {
    cin >> arrp[i];
  }
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < p; j++) {
      if (arr[i] == arrp[j]) {
        cout << arrp[j] << " ";
      }
    }
  }
  return 0;
}
