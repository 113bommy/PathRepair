#include <bits/stdc++.h>
using namespace std;
char a[105];
int aa[28] = {0};
int main() {
  int n;
  cin >> n;
  cin >> a;
  if (strlen(a) < n) {
    cout << "NO";
    return 0;
  } else {
    for (int i = 0; i < 27; ++i) {
      aa[i] = strlen(a);
    }
    int h = 0;
    h = 1;
    aa[0] = 0;
    for (int i = 0; i <= strlen(a); ++i) {
      int jj = 0;
      if (h < n) {
        for (int j = 0; j < h; ++j) {
          if (a[i] == a[aa[j]]) {
            jj = 1;
          }
        }
        if (jj == 0) {
          aa[h] = i;
          h++;
        }
      } else {
        cout << "YES" << endl;
        for (int p = 0; p < n; ++p) {
          for (int hh = aa[p]; hh < aa[p + 1]; hh++) {
            cout << a[hh];
          }
          cout << endl;
        }
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
