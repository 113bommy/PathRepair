#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a == 4) {
    cout << 4 << endl;
    exit(0);
  }
  cout << (a % 3) + 1 << endl;
}
