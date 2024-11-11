#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, t, i, j, k, m;
  cin >> t;
  vector<int> val;
  vector<vector<int>> mas;
  for (i = 0; i < t; i++) {
    cin >> n >> a >> b;
    val.push_back(n);
    val.push_back(a);
    val.push_back(b);
    mas.push_back(val);
    val.clear();
  }
  string tmp_str = "";
  string str = "abcdefghijklmnopqstuvwxyz";
  for (m = 0; m < t; m++) {
    n = mas[m][0];
    a = mas[m][1];
    b = mas[m][2];
    if (a == 1) {
      for (i = 0; i < n; i++) {
        cout << str[0];
      }
      cout << endl;
      continue;
    }
    if (b == 1) {
      for (i = 0; i < n; i++) {
        cout << str[0];
      }
      cout << endl;
      continue;
    }
    if (n == a) {
      for (j = 0; j < n;) {
        for (k = 0; k < b && j < n; k++) {
          cout << str[k];
          j++;
        }
      }
      cout << endl;
      continue;
    }
    if (a == b) {
      for (i = 0; i < n;) {
        for (j = 0; j < a && i < n; j++) {
          cout << str[j];
          i++;
        }
      }
      cout << endl;
      continue;
    }
    for (i = 0; i < n;) {
      for (j = 0; j < b && i < n; j++) {
        cout << str[j];
        i++;
      }
    }
    cout << endl;
  }
  return 0;
}
