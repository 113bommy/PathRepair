#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(b, c) << " " << max(0, a - b - c) << endl;
  return 0;
}
