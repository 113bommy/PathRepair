#include <bits/stdc++.h>
using namespace std;
int main() {
  int tog[10] = {0};
  int firs[10] = {0};
  int second[10] = {0};
  int a, b;
  cin >> a >> b;
  int tmp;
  for (int i = 0; i < a; i++) {
    cin >> tmp;
    tog[tmp]++;
    firs[tmp]++;
  }
  for (int i = 0; i < a; i++) {
    cin >> tmp;
    tog[tmp]++;
    second[tmp]++;
  }
  for (int i = 0; i <= 9; i++) {
    if (tog[i] == 2) {
      cout << i << endl;
      return 0;
    }
  }
  for (int i = 0; i < 10; i++) {
    if (firs[i] == 1) {
      for (int j = i; j < 10; j++) {
        if (second[j] == 1) {
          if (i < j) {
            cout << i << j << endl;
            return 0;
          } else {
            cout << j << i << endl;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
