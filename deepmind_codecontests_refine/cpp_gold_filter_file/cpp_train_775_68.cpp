#include <bits/stdc++.h>
using namespace std;
int n1, n2, k1, k2;
int main() {
  cin >> n1 >> n2 >> k1 >> k2;
  if (n1 <= n2) {
    cout << "Second";
    return 0;
  }
  cout << "First";
  return 0;
}
