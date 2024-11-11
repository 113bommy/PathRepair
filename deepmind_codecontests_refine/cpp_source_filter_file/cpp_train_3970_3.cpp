#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int n;
  cin >> n;
  string a[2 * n - 2];
  char afinal[2 * n - 2];
  string atemp[2 * n - 2];
  int coorolation[2 * n - 2];
  for (int i = 0; i < 2 * n - 2; i++) {
    cin >> a[i];
    if (atemp[(a[i].length() - 1) * 2] == "") {
      atemp[(a[i].length() - 1) * 2] = a[i];
      coorolation[(a[i].length() - 1) * 2] = i;
    } else {
      atemp[(a[i].length() - 1) * 2 + 1] = a[i];
      coorolation[(a[i].length() - 1) * 2 + 1] = i;
    }
  }
  char atempx[2 * n - 2];
  for (int i = 0; i < 2 * n - 2; i++) {
    atempx[i] = 'A';
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      string temp = atemp[i] + atemp[2 * n - 2 - 1 - j];
      string temp1 = atemp[2 * n - 2 - 1 - (1 - j)] + atemp[1 - i];
      if (temp == temp1) {
        int flag = 0;
        char tempz[2 * n - 2];
        for (int k = 0; k < n - 1; k++) {
          string tempstart, tempend;
          for (int l = 0; l <= k; l++) {
            tempstart = tempstart + temp[l];
            tempend = tempend + temp[2 * n - 2 - 2 - (k - l)];
          }
          flag = 0;
          if (tempstart == atemp[2 * k] && tempend == atemp[2 * k + 1]) {
            tempz[2 * k] = 'P';
            tempz[2 * k + 1] = 'S';
            flag = 1;
          } else if (tempend == atemp[2 * k] && tempstart == atemp[2 * k + 1]) {
            tempz[2 * k] = 'S';
            tempz[2 * k + 1] = 'P';
            flag = 1;
          }
          if (flag == 0) {
            break;
          }
        }
        if (flag == 1) {
          for (int i = 0; i < 2 * n - 2; i++) {
            atempx[i] = tempz[i];
          }
        }
      }
    }
  }
  for (int i = 0; i < 2 * n - 2; i++) {
    afinal[coorolation[i]] = atempx[i];
  }
  for (int i = 0; i < 2 * n - 2; i++) {
    cout << afinal[i];
  }
  cout << endl;
  return 0;
}
