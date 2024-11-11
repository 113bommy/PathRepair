#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if ((i * i) + i / 2 == n) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
