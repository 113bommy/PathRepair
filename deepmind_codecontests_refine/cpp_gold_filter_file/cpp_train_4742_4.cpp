#include <bits/stdc++.h>
using namespace std;
int main() {
  int R, C;
  cin >> R >> C;
  char temp;
  int seg = 0;
  int l = 0;
  for (int i = 0; i < (R - 1) * C; i++) {
    cin >> temp;
  }
  for (int i = 0; i < C; i++) {
    cin >> temp;
    if (temp == 'B') {
      l++;
    } else {
      if (l != 0) {
        seg++;
        l = 0;
      }
    }
  }
  if (l > 0) seg++;
  cout << seg << endl;
  return 0;
}
