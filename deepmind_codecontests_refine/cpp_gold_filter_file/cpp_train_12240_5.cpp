#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
  cin >> n >> m >> k;
  k--;
  int l = k % 2;
  k /= 2;
  int x = k / m;
  int y = k % m;
  cout << x + 1 << endl;
  cout << y + 1 << endl;
  if (l == 0) {
    cout << "L" << endl;
  } else {
    cout << "R" << endl;
  }
}
