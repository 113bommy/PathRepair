#include <bits/stdc++.h>
using namespace std;
int n, a[200002], d[200002], b[200002], ja, ga, c, v;
void shift(int j) {
  for (int i = 1; i <= n - j - 1; i++) d[i + j] = a[i];
  for (int i = 1; i <= j; i++) d[i] = a[n - j + i - 1];
  for (int i = 1; i <= n - 1; i++) a[i] = d[i];
}
int main() {
  cin >> n;
  if (n == 1) {
    cin >> c >> v;
    cout << "YES";
    return 0;
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      i--;
      continue;
    }
    if (a[i] == 1) ja = i;
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> b[i];
    if (b[i] == 0) {
      i--;
      continue;
    }
    if (b[i] == 1) ga = i;
  }
  if (ga >= ja) {
    ga -= ja;
    shift(ga);
    for (int i = 1; i <= n - 1; i++) {
      if (a[i] != b[i]) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
    return 0;
  } else {
    int l = n - ja + ga;
    shift(l);
    for (int i = 1; i <= n - 1; i++) {
      if (a[i] != b[i]) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
    return 0;
  }
}
