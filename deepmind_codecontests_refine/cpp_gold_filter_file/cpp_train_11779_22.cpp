#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, z, a, b, c, sum = 0;
  cin >> x >> y >> z >> a >> b >> c;
  if (a - x >= 0) {
    sum = (a - x) + b;
    if ((sum - y) >= 0) {
      sum = (sum - y) + c;
      if (sum - z >= 0)
        cout << "YES";
      else
        cout << "NO";
    } else
      cout << "NO";
  } else {
    cout << "NO";
  }
}
