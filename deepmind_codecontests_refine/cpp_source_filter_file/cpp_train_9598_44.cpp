#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  cout << min(b + 1, n - a);
  return 0;
}
