#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> b;
    cout << (1 << __builtin_popcount(b)) << endl;
  }
}
