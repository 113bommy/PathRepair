#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n][2];
  string str;
  cin >> str;
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0];
    arr[i][1] = 0;
  }
  arr[0][1] = 1;
  int pos = 0;
  while (true) {
    if (str[pos] == '>') {
      if (arr[pos][0] + (pos + 1) > n) {
        cout << "FINITE" << endl;
        break;
      } else {
        pos = pos + arr[pos][0];
        if (arr[pos][1] == 1) {
          cout << "INFINITE" << endl;
          break;
        }
        arr[pos][1] = 1;
      }
    }
    if (str[pos] == '<') {
      if ((pos + 1) - arr[pos][0] <= 0) {
        cout << "FINITE" << endl;
        break;
      } else {
        pos = pos - arr[pos][0];
        if (arr[pos][1] == 1) {
          cout << "INFINITE" << endl;
          break;
        }
        arr[pos][1] = 1;
      }
    }
  }
}
