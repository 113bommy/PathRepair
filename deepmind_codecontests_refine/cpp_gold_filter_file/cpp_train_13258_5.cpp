#include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000];
int main() {
  int n, s;
  int swap;
  cin >> s >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < n; i++)
    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) {
        swap = a[i - 1];
        a[i - 1] = a[i];
        a[i] = swap;
        swap = b[i - 1];
        b[i - 1] = b[i];
        b[i] = swap;
      }
    }
  int i;
  for (i = 0; i < n; i++) {
    if (s > a[i])
      s += b[i];
    else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
