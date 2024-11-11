#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int B[n];
  B[0] = (s[0] == '(' ? 1 : -1);
  for (int i = 1; i < n; i++) {
    B[i] = B[i - 1] + (s[i] == '(' ? 1 : -1);
  }
  if (B[n - 1] == 2) {
    bool f = false;
    for (int i = 0; i < n; i++)
      if (B[i] < 0) {
        f = true;
        break;
      }
    if (f == true)
      cout << 0;
    else {
      int k = 0;
      int j = n - 1;
      while (B[j] >= 2) j--;
      for (int i = j + 1; i < n; i++) {
        if (s[i] == '(' and B[i] >= 2) k += 1;
      }
      cout << k;
    }
  } else if (B[n - 1] == -2) {
    bool f = false;
    for (int i = 0; i < n; i++)
      if (B[i] < -2) {
        f = true;
        break;
      }
    if (f == true)
      cout << 0;
    else {
      int k = 0;
      int j = 0;
      while (B[j] >= 0) j++;
      for (int i = 0; i <= j; i++) {
        if (s[i] == ')') k += 1;
      }
      cout << k;
    }
  } else
    cout << 0;
}
