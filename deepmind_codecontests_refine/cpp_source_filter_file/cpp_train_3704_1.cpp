#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  int a[40];
  cin >> x;
  if (x[0] != 'a') {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < 40; i++) a[i] = 0;
  for (int i = 0; i < x.length() - 1; i++) {
    if (a[x[i + 1] - 'a'] == 0 && x[i + 1] - x[i] > 1) {
      cout << "NO";
      return 0;
    }
    a[x[i] - 'a']++;
  }
  cout << "YES";
  return 0;
}
