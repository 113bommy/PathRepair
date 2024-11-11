#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  for (int i = 0; i < a; i++) {
    int c = 0;
    int j;
    cin >> j;
    int f = j % 10;
    if (j > 1) f = (f - 1) * 10;
    if (j > 1000) {
      f = f + 10;
    } else if (j > 100) {
      f = f + 6;
    } else if (j > 10) {
      f = f + 3;
    } else if (j > 1 && j < 10) {
      f = f + 1;
    }
    cout << f << endl;
  }
}
