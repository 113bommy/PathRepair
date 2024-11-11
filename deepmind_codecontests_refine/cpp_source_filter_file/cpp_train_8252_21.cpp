#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << n - 1 << "\n";
    for (int i = 1; i < n; i++) cout << i << " \n"[i == n - 1];
  }
  return 0;
}
