#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, l;
  cin >> n;
  string s;
  cin >> s;
  char a[n];
  if (s[0] == '0') {
    a[0] = '1';
    for (i = 1; i < n; i++) {
      a[i] = s[i];
    }
  } else {
    int flag = 1;
    a[0] = '0';
    for (i = 1; i < n; i++) {
      if (s[i] == '0' && flag == 1) {
        a[i] = '1';
        flag = 0;
      } else if (flag == 1 && s[i] == 1) {
        a[i] = '0';
      } else if (flag == 0) {
        a[i] = s[i];
      }
    }
  }
  int sum = 0;
  for (i = 0; i < n; i++) {
    if (s[i] != a[i]) sum++;
  }
  cout << sum;
}
