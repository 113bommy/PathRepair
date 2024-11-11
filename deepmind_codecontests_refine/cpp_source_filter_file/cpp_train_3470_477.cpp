#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a == 5) {
    cout << 0 << endl;
    exit(0);
  }
  cout << (a % 3) + 1 << endl;
}
