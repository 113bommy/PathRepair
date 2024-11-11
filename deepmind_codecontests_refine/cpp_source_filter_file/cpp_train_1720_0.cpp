#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; n - i > 0; i++) {
    n = n - i;
  }
  cout << n;
  return 0;
}
