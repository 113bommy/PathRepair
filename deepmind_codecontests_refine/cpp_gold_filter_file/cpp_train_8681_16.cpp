#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int l[n], c[n];
  for (int i = 0; i < n; i++) l[i] = c[i] = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char ci;
      cin >> ci;
      if (ci == '.') {
        l[i] = j;
        c[j] = i;
      }
    }
  }
  bool li = true, cj = true;
  for (int i = 0; i < n; i++)
    if (l[i] < 0) {
      li = false;
      break;
    }
  for (int i = 0; i < n; i++)
    if (c[i] < 0) {
      cj = false;
      break;
    }
  if (li) {
    for (int i = 0; i < n; i++) {
      cout << i + 1 << ' ' << l[i] + 1 << endl;
    }
  } else if (cj) {
    for (int i = 0; i < n; i++) {
      cout << c[i] + 1 << ' ' << i + 1 << endl;
    }
  } else
    cout << "-1\n";
  return 0;
}
