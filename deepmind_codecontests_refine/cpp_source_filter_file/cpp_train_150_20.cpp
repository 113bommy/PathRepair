#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int len;
  cin >> len;
  string save;
  cin >> save;
  int counter = 0;
  for (int i = 0; i < len; i++) {
    if (save[i] == '*') {
      int counter = 0;
      for (int j = 1; j < 26; j++) {
        if (save[i + j] == '*') {
          counter++;
          for (int k = i + j + j; k < len; k += j) {
            if (save[k] == '*') {
              counter++;
            } else {
              counter = 0;
              break;
            }
            if (counter > 3) {
              cout << "yes\n";
              return 0;
            }
          }
        } else
          counter = 0;
      }
    }
  }
  cout << "no\n";
  return 0;
}
