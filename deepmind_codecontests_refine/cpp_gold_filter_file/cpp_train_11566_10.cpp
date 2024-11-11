#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int c = 0;
  int i;
  i = 0;
  while (i < n) {
    cin >> a[i];
    if (a[i] == 1) {
      c++;
    }
    i++;
  }
  cout << c << "\n";
  i = 1;
  while (i <= n - 1) {
    if (a[i] == 1) {
      cout << a[i - 1] << " ";
    }
    i++;
  }
  cout << a[n - 1];
  return 0;
}
