#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  string s;
  int a[20];
  cin >> n;
  cin >> s;
  for (int i = 0; i < 9; i++) cin >> a[i];
  for (int k = 0; k < n; k++) {
    if (s[k] - '0' <= a[s[k] - '0' - 1]) {
      d = k;
      break;
    }
  }
  for (int j = d; j < n; j++) {
    if (s[j] - '0' <= a[s[j] - '0' - 1]) {
      s[j] = a[s[j] - '0' - 1] + '0';
      if (s[j + 1] - '0' > a[s[j + 1] - '0' - 1]) break;
    }
  }
  cout << s;
  return 0;
}
