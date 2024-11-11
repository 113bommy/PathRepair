#include <bits/stdc++.h>
using namespace std;
int k, n;
int main() {
  k = 1;
  cin >> n;
  while (k <= n) {
    if (k == n) {
      cout << "YES";
      return 0;
    }
    k *= 2;
  }
  cout << "NO";
}
