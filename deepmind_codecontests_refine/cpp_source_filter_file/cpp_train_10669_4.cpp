#include <bits/stdc++.h>
using namespace std;
int main() {
  long a[2000], b[2000];
  int n, tmp, j, l, u, m;
  cin >> n;
  l = 0;
  u = n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  for (int i = 1; i < n; i++) {
    tmp = a[i];
    j = i - 1;
    while (j >= 0 && b[j] < tmp) {
      b[j + 1] = b[j];
      --j;
    }
    b[j + 1] = tmp;
  }
  for (int i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i] == b[j]) {
        cout << j + 1;
        break;
      }
    }
  }
}
