#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a == 1) {
    cout << 1;
    return 0;
  }
  cout << (a - 1) * (a - 1) * (a * a);
}
