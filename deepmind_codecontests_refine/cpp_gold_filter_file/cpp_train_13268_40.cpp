#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  int y[100];
  int z[100];
  cin >> x;
  int a{0};
  for (int i{0}; i < x; ++i) {
    cin >> y[i] >> z[i];
    if (z[i] - y[i] >= 2) ++a;
  }
  cout << a;
}
