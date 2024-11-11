#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 3];
  int i;
  int off = 0;
  a[0] = 0;
  a[1] = 0;
  a[2] = 0;
  for (i = 3; i < n + 3; i++) {
    cin >> a[i];
    if (i < n + 2) {
      if (a[i] == 0) {
        if (a[i - 1] == 1 && a[i - 2] == 0 && a[i - 3] == 1) {
          off--;
        }
      } else {
        if (a[i - 1] == 0 && a[i - 2] == 1) {
          off++;
          a[i] = 0;
        }
      }
    }
  }
  cout << off;
}
