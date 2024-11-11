#include <bits/stdc++.h>
using namespace std;
int main() {
  string str1[1][2];
  for (int i = 0; i < 2; i++) {
    cin >> str1[0][i];
  }
  int n;
  cin >> n;
  string str2[n][2];
  string str3[n + 1][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) cin >> str2[i][j];
  }
  str3[0][0] = str1[0][0];
  str3[0][1] = str1[0][1];
  for (int i = 0; i < n; i++) {
    if (str2[i][0] == str3[i][0]) {
      str3[i + 1][0] = str2[i][1];
      str3[i + 1][1] = str3[i][1];
    } else if (str2[i][0] == str3[i][1]) {
      str3[i + 1][0] = str2[i][1];
      str3[i + 1][1] = str3[i][0];
    }
  }
  for (int i = 0; i < n + 1; i++) {
    cout << str3[i][0] << " " << str3[i][1] << endl;
  }
  return 0;
}
