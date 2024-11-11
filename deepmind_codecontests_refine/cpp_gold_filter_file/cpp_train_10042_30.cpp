#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i = 1;
  int j = 1;
  while (j <= n) {
    if (j == n) {
      cout << "YES\n";
      return 0;
    }
    i++;
    j += i;
  }
  cout << "NO\n";
  return 0;
}
