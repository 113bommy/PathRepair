#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    char arr1[n + 1], arr2[n + 1];
    cin >> arr1;
    cin >> arr2;
    int flag = 0, flag2 = 1;
    for (int i = 0; i < n; i++) {
      if (flag == 0) {
        if (arr1[i] - '0' > 2) {
          flag = (flag + 1) % 2;
          if (arr2[i] - '0' <= 2) {
            cout << "NO" << endl;
            flag2 = 0;
            break;
          }
        }
      } else if (flag == 1) {
        if (arr2[i] - '0' > 2) {
          flag = (flag + 1) % 2;
          if (arr1[i] - '0' <= 2) {
            cout << "NO" << endl;
            flag2 = 0;
            break;
          }
        }
      }
    }
    if (flag2 == 1) {
      if (flag == 0)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }
  return 0;
}
