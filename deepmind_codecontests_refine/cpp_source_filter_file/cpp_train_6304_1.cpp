#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  int t;
  int a[200000];
  cin >> n >> t;
  cin.get();
  for (i = 0; i < n; i++) a[i] = (int)cin.get() - 48;
  i = 0;
  while (a[i] != -2) i++;
  while (a[i] < 5 && i < n - 1) i++;
  i++;
  while (t != 0 && a[i] != -2) {
    i--;
    t--;
    if (a[i] >= 5) {
      a[i - 1]++;
      a[i] = 0;
      if (a[i - 1] == 10) {
        while (a[i - 1] == 10 && a[i - 1] != -2) {
          i--;
          a[i - 1]++;
          a[i] = 0;
        };
      };
    } else {
      i++;
      break;
    }
    if (a[i - 1] == -1) {
      t = i;
      i--;
      a[i - 1]++;
      while (a[i - 1] >= 9 && i != 1) {
        i--;
        a[i - 1]++;
        a[i] = 0;
      };
      i = t;
      break;
    };
  };
  cout << endl;
  n = i;
  for (i = 0; i < n; i++) {
    if (a[i] == -2) {
      cout << ".";
    } else if (a[i] == -1) {
      break;
    } else
      cout << a[i];
  };
  return 0;
}
