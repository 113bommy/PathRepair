#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, *a, tmp;
  cin >> n;
  a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int b = 0; b < n; b++) {
      if (a[i] < a[b]) {
        tmp = a[b];
        a[b] = a[i];
        a[i] = tmp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i];
  }
}
