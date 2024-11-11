#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  int a = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'N') {
      a++;
      if (max < a) {
        max = a;
      }
    } else {
      if (max < a) {
        max = a;
      }
      a = 0;
    }
  }
  if (max > k) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0 && s[i - 1] == 'N') {
      continue;
    }
    bool b = true;
    for (int j = i; j < i + k; j++) {
      if (s[j] == 'Y') {
        b = false;
        break;
      }
    }
    if (b && (i + k == n || s[i + k] != 'N')) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
