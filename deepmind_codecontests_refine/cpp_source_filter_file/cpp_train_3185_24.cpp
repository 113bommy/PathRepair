#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  float a, b;
  cin >> a >> b;
  float ans = log(a / b) / log(2.0 / 3.0);
  cout << (int)ans + 1;
  return 0;
}
