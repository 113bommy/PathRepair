#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long int a[n], b[n];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    b[i] = a[i] + a[i + 1];
  }
  b[n] = a[n];
  for (int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
}
