#include <bits/stdc++.h>
using namespace std;
int a[6] = {12, 6, 4, 3, 2, 1};
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    vector<int> v;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < a[i]; j++) {
        bool flag = true;
        for (int k = 0; k < 12 / a[i]; k++) {
          if (str[k * a[i] + j] == 'O') {
            flag = false;
            break;
          }
        }
        if (flag) {
          v.push_back(a[i]);
          break;
        }
      }
    }
    cout << v.size() << " ";
    for (int i = 0; i < v.size(); i++) {
      cout << 12 / v[i] << "x" << v[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
