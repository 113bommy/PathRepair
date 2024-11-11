#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int t, b, nxt;
  string s;
  bool bol = 0;
  cin >> t;
  while (t--) {
    bol = 1;
    cin >> s;
    v.clear();
    for (int a = 1; a <= 12; a++) {
      if (12 % a) continue;
      b = 12 / a;
      int arr[a][b];
      nxt = 0;
      for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
          if (s[nxt++] == 'X')
            arr[i][j] = 1;
          else
            arr[i][j] = 0;
        }
      }
      for (int j = 0; j < b; j++) {
        bol = 1;
        for (int i = 0; i < a; i++) {
          if (!arr[i][j]) bol = 0;
        }
        if (bol) {
          v.push_back(a);
          break;
        }
      }
    }
    cout << v.size();
    for (int i = 0; i < v.size(); i++) cout << " " << v[i] << "*" << 12 / v[i];
    cout << endl;
  }
  return 0;
}
