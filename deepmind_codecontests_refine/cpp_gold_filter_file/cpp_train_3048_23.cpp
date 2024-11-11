#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n1, n2;
  while (t--) {
    cin >> n1 >> n2;
    cout << (n1 ^ n2) << endl;
  }
}
