#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, count = 0;
  cin >> n >> d;
  string s;
  cin >> s;
  int i = 0, j = 0, ind, f = 0, f1 = 0;
  while (i < n && j + d <= n) {
    for (int i = j; i < j + d; i++) {
      if (s[i] == '1') {
        f = 1;
        ind = i;
      }
    }
    j = ind + 1;
    i = j;
    if (f) {
      count++;
      f = 0;
      f1 = 1;
    } else {
      f1 = 0;
      break;
    }
  }
  if (f1)
    cout << count;
  else
    cout << -1;
}
