#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int t;
    cin >> t;
    int arr[t];
    int brr[t];
    for (int i = 0; i < t; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < t; i++) {
      cin >> brr[i];
    }
    int a, b, c;
    int f;
    a = b = c = -2;
    int i;
    for (i = 0; i < t; i++) {
      f = i;
      int d = arr[i];
      int e = brr[i];
      if (i == 0) {
        if (d == e) {
          if (d == 1) a = 1;
          if (d == 0) b = 0;
          if (d == -1) c = -1;
          continue;
        } else
          break;
      }
      if ((e > d) && (a == -2)) break;
      if ((e < d) && (c == -2)) break;
      if (d == 1) a = 1;
      if (d == 0) b = 0;
      if (d == -1) c = -1;
    }
    if (i == t)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
