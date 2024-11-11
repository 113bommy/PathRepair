#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (pow(2, i) == n) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
