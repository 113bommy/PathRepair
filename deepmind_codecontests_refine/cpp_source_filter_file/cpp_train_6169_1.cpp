#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n;
    cin >> n;
    if ((n - 4) % 2 == 0)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
