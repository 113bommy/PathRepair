#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> day;
  day["monday"] = 1;
  day["tuesday"] = 2;
  day["wednesday"] = 3;
  day["thursday"] = 4;
  day["friday"] = 5;
  day["saturday"] = 6;
  day["sunday"] = 0;
  string x, y;
  int a, b;
  cin >> x >> y;
  a = day[x];
  b = day[y];
  if ((b + 4) % 7 == a || (b + 5) % 7 == a || a == b)
    cout << "YES\n";
  else
    cout << "NO\n";
}
