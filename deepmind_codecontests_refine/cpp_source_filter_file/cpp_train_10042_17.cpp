#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; n > i; i++) {
    if (i * (i + 1) / 2 == n) {
      cout << "YES";
      return 1;
    }
  }
  cout << "NO";
  return 0;
}
