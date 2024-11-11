#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  int x = 0;
  while (x <= n) {
    x += k;
  }
  cout << x << endl;
  return 0;
}
