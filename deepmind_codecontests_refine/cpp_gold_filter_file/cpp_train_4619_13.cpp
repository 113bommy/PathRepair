#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b[10000], i, j, count = 0, flag = 0, z = 0;
  cin >> a;
  int y = a;
  while (a != 0) {
    for (i = 0; i < 3; i++) {
      cin >> b[i];
    }
    for (j = 0; j < 3; j++) {
      if (b[j] == 1) {
        ++count;
      }
    }
    if (count >= 2) {
      ++flag;
      z = z + flag;
    }
    count = 0;
    flag = 0;
    a--;
  }
  cout << z << endl;
}
