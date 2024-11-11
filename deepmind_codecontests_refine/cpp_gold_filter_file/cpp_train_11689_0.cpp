#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a1, b1, c1, a2, b2, c2, mini = 0;
  cin >> n >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  int maxi = min(a1, b2) + min(b1, c2) + min(c1, a2);
  mini = max({0, a1 - a2 - c2, b1 - b2 - a2, c1 - c2 - b2});
  cout << mini << " " << maxi << endl;
}
