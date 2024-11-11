#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1)
      cout << "1";
    else if (n == 2 || n == 3)
      cout << "2";
    else
      cout << "3";
    cout << "\n";
  }
  return 0;
}
