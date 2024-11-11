#include <bits/stdc++.h>
using namespace std;
const int N = 2e2;
long long a[N], b[N], c[N], d[N];
int main() {
  for (int i = 1; i <= 4; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    if (max(a[i], max(b[i], c[i])) + d[i] == 2) {
      cout << "YES";
      return 0;
    }
  }
  if (a[1] == 1 && d[4] == 1) {
    cout << "YES";
    return 0;
  }
  if (c[1] == 1 && d[2] == 1) {
    cout << "YES";
    return 0;
  }
  if (b[1] == 1 && d[3] == 1) {
    cout << "YES";
    return 0;
  }
  if (a[2] == 1 && d[1] == 1) {
    cout << "YES";
    return 0;
  }
  if (c[2] == 1 && d[3] == 1) {
    cout << "YES";
    return 0;
  }
  if (b[2] == 1 && d[4] == 1) {
    cout << "YES";
    return 0;
  }
  if (a[3] == 1 && d[2] == 1) {
    cout << "YES";
    return 0;
  }
  if (c[3] == 1 && d[4] == 1) {
    cout << "YES";
    return 0;
  }
  if (b[3] == 1 && d[1] == 1) {
    cout << "YES";
    return 0;
  }
  if (a[4] == 1 && d[3] == 1) {
    cout << "YES";
    return 0;
  }
  if (c[4] == 1 && d[1] == 1) {
    cout << "YES";
    return 0;
  }
  if (b[4] == 1 && d[2] == 1) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
}
