#include <bits/stdc++.h>
using namespace std;
int main() {
  int L[51], N[101], a[51], b[51];
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i < n; i++) {
    N[i - 1] = a[i] - a[i - 1];
  }
  N[n - 1] = l - a[n - 1] + a[0];
  for (int i = 1; i < n; i++) {
    L[i - 1] = b[i] - b[i - 1];
  }
  L[n - 1] = l - b[n - 1] + b[0];
  for (int i = 0; i < n; i++) {
    int j;
    for (j = 0; j < n; j++) {
      if (N[i] != L[(i + j) % n]) {
        break;
      }
    }
    if (j == n) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
