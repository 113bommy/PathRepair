#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  char arr[4] = {0};
  int rct = 0, yct = 0, bct = 0, gct = 0;
  int n = str.size(), i, j;
  int s = ((n / 4) * 4);
  for (i = 0; i < s; i += 4) {
    for (j = i; j < i + 4; j++) {
      if (str[j] != '!') {
        arr[j - i] = str[j];
      }
    }
  }
  while (j < n) {
    if (str[j] != '!') {
      arr[j % 4] = str[j];
    }
    j++;
  }
  for (int k = 0; k < n; ++k) {
    if (str[k] == '!') {
      if (arr[k % 4] == 'R') {
        rct++;
      } else if (arr[k % 4] == 'B') {
        bct++;
      } else if (arr[k % 4] == 'Y') {
        yct++;
      } else if (arr[k % 4] == 'G') {
        gct++;
      }
    }
  }
  cout << rct << " " << bct << " " << yct << " " << gct << endl;
  return 0;
}
