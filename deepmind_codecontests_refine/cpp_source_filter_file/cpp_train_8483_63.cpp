#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int s1, s2;
  s1 = min(a, b);
  s2 = (a + b - min(a, b)) / 2;
  cout << s1 << " " << s2 << "\n";
  return 0;
}
