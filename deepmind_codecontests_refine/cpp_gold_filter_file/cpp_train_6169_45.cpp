#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n;
    cin >> n;
    if (n % 4 == 0)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
