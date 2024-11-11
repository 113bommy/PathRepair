#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int pos = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      pos = i + 1;
      break;
    }
  }
  int c = 0;
  for (int i = pos; i < n; i++) {
    b[c] = a[i];
    c++;
  }
  for (int i = 0; i < pos; i++) {
    b[c] = a[i];
    c++;
  }
  c = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      c++;
      break;
    }
  }
  if (c > 0)
    cout << -1;
  else if (pos == 0)
    cout << 0;
  else
    cout << n - pos;
}
