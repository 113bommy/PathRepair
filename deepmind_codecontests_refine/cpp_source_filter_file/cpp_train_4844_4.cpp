#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[200005];
  int b[200005];
  int ji1;
  int ji2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      ji1 = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] == 1) {
      ji2 = i;
    }
  }
  int k = ji1;
  int f = 0;
  for (int i = 1; i < n; i++) {
    if (ji1 == n) {
      ji1 = 0;
    } else {
      ji1++;
    }
    if (ji2 == n) {
      ji2 = 0;
    } else {
      ji2++;
    }
    if (a[ji1] == 0) {
      if (ji1 == n) {
        ji1 = 0;
      } else {
        ji1++;
      }
    }
    if (b[ji2] == 0) {
      if (ji2 == n) {
        ji2 = 0;
      } else {
        ji2++;
      }
    }
    if (a[ji1] != b[ji2]) {
      f = 1;
      cout << "NO";
      break;
    }
  }
  if (f == 0) {
    cout << "YES";
  }
}
