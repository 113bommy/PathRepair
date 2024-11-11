#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i <= 1e7; i++) {
    if ((n - (a * i)) % b == 0 && (n - (a * i)) >= 0) {
      cout << "YES" << endl;
      cout << i << " " << (n - (a * i)) / b << endl;
      return 0;
    }
    if (n - (a * i) < 0) break;
  }
  cout << "NO" << endl;
  return 0;
}
