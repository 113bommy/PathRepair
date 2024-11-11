#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  m--;
  if (m > n || ((n - m) % 2 != 0) || (m == 0 && n != 0)) {
    cout << "No";
    return 0;
  }
  cout << "Yes";
}
