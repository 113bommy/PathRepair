#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector<int> save;
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] != b[i]) {
        if (a[0] == b[i]) {
          save.push_back(1);
          if (a[0] == '0') {
            a[0] = '1';
          } else {
            a[0] = '0';
          }
        }
        string test = "";
        for (int j = i; j >= 0; j--) {
          if (a[j] == '0') {
            test += '1';
          } else {
            test += '0';
          }
        }
        if (test.size() > 0)
          for (int j = 0; j <= i; j++) {
            a[j] = test[j];
          }
        save.push_back(i + 1);
      }
    }
    cout << save.size() << " ";
    for (int i = 0; i < save.size(); i++) {
      cout << save[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
