#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
  cin >> a >> b >> c >> d;
  cout << max(0, (min(b, d) - min(a, c))) << endl;
  return 0;
}
