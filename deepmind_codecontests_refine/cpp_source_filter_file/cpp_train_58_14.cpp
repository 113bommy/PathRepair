#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[101];
int cur = 0;
void Alloc(int x) {
  for (int i = 1; i <= m; i++) {
    if (a[i] == 0) {
      bool was = true;
      for (int j = 0; j < x; j++) {
        if (a[i + j] != 0 || i + j > m) {
          was = false;
          break;
        }
      }
      if (was) {
        cur++;
        for (int j = i; j < i + x; j++) {
          a[j] = cur;
        }
        cout << cur << endl;
        return;
      }
    }
  }
  cout << "NULL" << endl;
}
string c[101];
int nu[101];
void myerase(int x) {
  bool was = false;
  for (int i = 1; i <= m; i++) {
    if (a[i] == x) {
      was = true;
      a[i] = 0;
    }
  }
  if (!was || x == 0) {
    cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
  }
}
void Defragment() {
  int k = 0, p = 0;
  while (p <= m) {
    p++;
    if (a[p] != 0) {
      k++;
      a[k] = a[p];
      if (k != p) a[p] = 0;
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    if (c[i] != "defragment") cin >> nu[i];
  }
  for (int i = 1; i <= n; i++) {
    if (c[i] == "alloc") {
      Alloc(nu[i]);
    } else if (c[i] == "erase") {
      myerase(nu[i]);
    } else {
      Defragment();
    }
  }
  return 0;
}
