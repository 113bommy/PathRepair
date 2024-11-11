#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  string c, d, e;
  cin >> a >> b >> c >> d;
  e += c[a - 1];
  e += c[0];
  e += d[b - 1];
  e += d[0];
  if (e == "><^v" || e == "<>V^")
    cout << "YES";
  else
    cout << "NO";
}
