#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1;
  int i, n, k = 0, a = 0, b = 0, c = 0;
  cin >> s1;
  n = s1.size();
  for (i = 0; i < n - 1; i++) {
    if (s1[i] > s1[i + 1]) {
      k++;
      break;
    }
  }
  for (i = 0; i < n; i++) {
    if (s1[i] == 'a') {
      a++;
    }
    if (s1[i] == 'b') {
      b++;
    }
    if (s1[i] == 'c') {
      c++;
    }
  }
  if (s1[0] == 'a' && s1[n - 1] == 'c' && a > 0 && b > 0 && c > 0) {
    if (k == 0 && (b == c || a == c)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  } else {
    cout << "NO";
  }
  return 0;
}
