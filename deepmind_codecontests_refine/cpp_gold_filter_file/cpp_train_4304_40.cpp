#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 12, b = 1;
  cin >> n;
  for (int i = 1; i < n; i++) {
    b += a;
    a += 12;
  }
  cout << b << endl;
}
