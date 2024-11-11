#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, c = 0, c1;
  cin >> n;
  long long int ara[n], i;
  for (i = 0; i < n; i++) {
    cin >> ara[i];
    if (ara[i] == 1) c++;
  }
  c1 = n - c;
  if (c == 0) {
    while (n--) {
      cout << 2 << endl;
    }
  } else if (c == 1) {
    if (c1 == 0) {
      cout << 1 << " ";
    } else if (c1 == 1) {
      cout << 2 << " ";
      cout << 1 << " ";
    } else {
      cout << 2 << " ";
      cout << 1 << " ";
      for (i = 0; i < c1 - 1; i++) {
        cout << 2 << " ";
      }
      for (i = 0; i < c - 1; i++) {
        cout << 1 << " ";
      }
    }
  } else {
    if (c1 == 0) {
      while (n--) {
        cout << 1 << " ";
      }
    } else if (c1 == 1) {
      cout << 2 << " ";
      while (c--) {
        cout << 1 << " ";
      }
    } else {
      cout << 2 << " ";
      cout << 1 << " ";
      for (i = 0; i < c1 - 1; i++) {
        cout << 2 << " ";
      }
      for (i = 0; i < c - 1; i++) {
        cout << 1 << " ";
      }
    }
  }
  return 0;
}
