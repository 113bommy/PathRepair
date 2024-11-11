#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      cout << "HARD";
      exit(0);
    }
  }
  cout << "EAZY";
}
