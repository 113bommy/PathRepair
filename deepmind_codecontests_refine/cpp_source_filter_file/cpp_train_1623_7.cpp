#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int min = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'N') {
      int c = 0;
      while ((i < n) && (s[i] == 'N')) {
        i++;
        c++;
        if (min < c) min = c;
      }
    }
  }
  if (k < min) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < n - k; i++) {
    if ((i > 0) && (s[i - 1] == 'N')) continue;
    bool f = true;
    for (int j = 0; j < k; j++)
      if (s[i + j] == 'Y') f = false;
    if ((i + k + 1 < n) && (s[i + k + 1] == 'N')) f = false;
    if (f) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
