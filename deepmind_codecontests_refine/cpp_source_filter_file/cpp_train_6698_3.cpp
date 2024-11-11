#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1], b[n + 1], x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    b[x] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
  return 0;
}
