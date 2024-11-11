#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  string a, b;
  cin >> a >> b;
  if (a.length() != b.length()) {
    cout << "NO";
    return 0;
  }
  long long n = b.length();
  if (n == 1) {
    if (a[0] == b[0]) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    return 0;
  }
  long long i = 0;
  for (i = 0; i < n; i++) {
    if (a[i] != '0') {
      break;
    }
  }
  long long j = 0;
  for (j = 0; j < n; j++) {
    if (a[j] != '0') {
      break;
    }
  }
  if ((j == n || i == n)) {
    if (i != j)
      cout << "NO";
    else
      cout << "YES";
  } else {
    cout << "YES";
  }
}
