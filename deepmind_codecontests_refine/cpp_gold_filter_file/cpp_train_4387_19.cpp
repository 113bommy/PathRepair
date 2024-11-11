#include <bits/stdc++.h>
using namespace std;
int main() {
  string line, a, b, c, d, e;
  cin >> line;
  cin >> a >> b >> c >> d >> e;
  if (a[0] == line[0] || a[1] == line[1])
    cout << "YES";
  else if (b[0] == line[0] || b[1] == line[1])
    cout << "YES";
  else if (c[0] == line[0] || c[1] == line[1])
    cout << "YES";
  else if (d[0] == line[0] || d[1] == line[1])
    cout << "YES";
  else if (e[0] == line[0] || e[1] == line[1])
    cout << "YES";
  else
    cout << "NO";
}
