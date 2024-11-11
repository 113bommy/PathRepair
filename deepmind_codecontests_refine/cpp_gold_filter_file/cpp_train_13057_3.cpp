#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    int count = 0, c[13] = {0};
    for (int i = 1; i <= 12; i++) {
      if (12 % i == 0) {
        int b = 12 / i;
        for (int j = 0; j < 12 / i; j++) {
          if (s[j] == 'X') {
            int k = j;
            int flag = 0;
            while ((k + b) < 12) {
              if (s[k + b] != 'X') {
                flag = 1;
                break;
              }
              k = k + b;
            }
            if (!flag) {
              count++;
              c[i] = 1;
              break;
            }
          }
        }
      }
    }
    cout << count << " ";
    for (int i = 1; i <= 12; i++) {
      if (c[i] == 1) cout << i << "x" << 12 / i << " ";
    }
    cout << endl;
  }
}
