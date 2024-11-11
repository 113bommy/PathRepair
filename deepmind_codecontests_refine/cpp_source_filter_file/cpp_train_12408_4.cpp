#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, Flag[15];
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    int flag = 0, Now = i;
    for (int j = 1; j <= 10; j++) Flag[j] = 0;
    do {
      if (Flag[Now % 10] == 0)
        Flag[Now % 10]++;
      else {
        flag = 1;
        break;
      }
    } while (Now /= 10);
    if (flag == 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
  return 0;
}
