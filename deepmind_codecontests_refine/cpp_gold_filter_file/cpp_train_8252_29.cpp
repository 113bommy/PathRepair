#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << n << "\n";
    for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
  }
  return 0;
}
