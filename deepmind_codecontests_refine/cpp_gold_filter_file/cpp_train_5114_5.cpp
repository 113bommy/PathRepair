#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int c = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n - 1; i++) {
    if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
      a[i + 1] = 0;
      c++;
    }
  }
  cout << c;
}
