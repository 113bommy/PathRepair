#include <bits/stdc++.h>
using namespace std;
vector<int> f() {
  vector<int> x;
  x.push_back(4);
  return x;
}
int main(void) {
  int x, y, z;
  int a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  if (x <= a && y <= b + c && z <= a + b + c - x - y)
    cout << "YES";
  else
    cout << "NO";
}
