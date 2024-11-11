#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int n;
    cin >> n;
    if (n % 4 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
