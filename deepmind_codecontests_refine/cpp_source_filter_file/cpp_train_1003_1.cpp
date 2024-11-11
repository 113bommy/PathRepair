#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[15];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int max = 0;
    for (int i = 1; i < n; i++) {
      if (abs(a[i] - a[i + 1]) >= 2) {
        cout << "NO";
        return false;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] > a[max]) {
        max = i;
      }
    }
    int tmp = a[max];
    for (int i = max + 1; i <= n; i++) {
      a[i - 1] = a[i];
    }
    a[n] = tmp;
  }
  cout << "YES";
  return 0;
}
