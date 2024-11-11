#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int count;
    count = (int)sqrt(n) + (int)cbrt(n) - (int)sqrt(cbrt(n));
    cout << count << "\n";
  }
  return 0;
}
