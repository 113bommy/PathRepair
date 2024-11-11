#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, k1, n2, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  if (n2 >= n1) {
    cout << "Second";
    return 0;
  }
  cout << "First";
}
