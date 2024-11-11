#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int n = a.length();
  for (int i = 0; i < n; i++) {
    if (b[i] - a[i] >= 2) {
      if (a[i] != 'z') {
        for (int j = 0; j < i; j++) cout << a[j];
        cout << char(a[i] + 1);
        for (int j = i + 1; j < n; j++) cout << a[j];
        return 0;
      }
    }
    if (b[i] - a[i] == 1 && i != n - 1) {
      for (int k = i + 1; k < n; k++) {
        if (b[k] <= a[k] && b[k] != 'a') {
          for (int j = 0; j < i; j++) cout << a[j];
          cout << char(a[i] + 1);
          for (int j = i + 1; j < n; j++) cout << 'a';
          return 0;
        }
      }
      if (a[i + 1] != 'z') {
        for (int j = 0; j <= i; j++) cout << a[j];
        cout << char(a[i + 1] + 1);
        for (int j = i + 2; j < n; j++) cout << a[j];
        return 0;
      }
    }
  }
  cout << "No such string";
  return 0;
}
