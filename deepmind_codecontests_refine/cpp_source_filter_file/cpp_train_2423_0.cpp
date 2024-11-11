#include <bits/stdc++.h>
using namespace std;
int main() {
  int TC, te = 0;
  cin >> TC;
  while (te++ < TC) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i = i + 2) {
      cout << -a[i + 1] << " " << a[i];
    }
    cout << endl;
  }
}
