#include <bits/stdc++.h>
using namespace std;
int main() {
  string ar;
  cin >> ar;
  int l = ar.length();
  int p = 0, c = 0, sum = 0;
  for (int i = 0; i < l; i++) {
    if (ar[i] == 'C') {
      c++;
      if (p > 0 && p < 5) {
        sum = sum + 1;
        p = 0;
      }
      if (c == 5) {
        sum += 1;
        c = 0;
      }
    } else if (ar[i] == 'P') {
      p++;
      if (c > 0 && c < 5) {
        sum += 1;
        c = 0;
      }
      if (p == 5) {
        sum = sum + 1;
        p = 0;
      }
    }
  }
  if (c > 0 || p > 0) {
    sum += 1;
  }
  cout << sum << endl;
  return 0;
}
