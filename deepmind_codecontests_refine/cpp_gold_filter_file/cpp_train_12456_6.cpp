#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 10];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[a[a[i]]] == i) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
