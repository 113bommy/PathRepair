#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x;
  cin >> a >> b >> x;
  cout << (a + b < x || x < a ? "NO" : "YES") << endl;
}