#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= 32; ++i) {
    if (i * (i + 1) == (n << 1)) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
