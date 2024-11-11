#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m = 0, c = 0;
  cin >> n;
  char ch[n][7];
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    for (int j = 0; j < 7; j++) {
      ch[i][j] = a[j];
    }
  }
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < n; j++) {
      if (ch[j][i] == '1') {
        c++;
      }
    }
    if (c > m) {
      m = c;
    }
    c = 0;
  }
  cout << m;
  return 0;
}
