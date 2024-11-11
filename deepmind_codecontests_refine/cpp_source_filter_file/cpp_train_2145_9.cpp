#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int n, k;
  cin >> n >> k;
  if (k > 1) {
    cout << "Yes";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int b;
  cin >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      a[i] = b;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] >= a[i + 1]) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
