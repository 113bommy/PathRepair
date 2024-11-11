#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[a[a[i]]] == a[i]) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
