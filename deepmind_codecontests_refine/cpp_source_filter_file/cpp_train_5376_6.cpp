#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n >= 25)
    cout << m;
  else {
    int y = pow(2, n);
    cout << (m % y);
  }
}
