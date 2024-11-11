#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int mn = min(a, b);
  int s = 0;
  if (mn != a) {
    s = (a - mn) / 2;
  }
  if (mn != b) {
    s = (b - mn) / 2;
  }
  cout << mn << " " << s << endl;
  return 0;
}
