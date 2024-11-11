#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 35; i++) {
    if ((i * (i + 1)) / 2 == n) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
