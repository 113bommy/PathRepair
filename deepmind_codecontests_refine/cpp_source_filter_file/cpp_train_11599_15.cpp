#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  while (n) {
    if (n % 10 != 1 && n % 100 != 14 && n % 100 != 144) {
      cout << "NO" << endl;
      break;
    }
    n /= 10;
  }
  if (!n) {
    cout << "YES" << endl;
  }
}
