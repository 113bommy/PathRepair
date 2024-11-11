#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    if (i * (i + 1) / 2 == n) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
