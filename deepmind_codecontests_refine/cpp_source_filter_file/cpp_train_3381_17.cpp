#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, s;
  cin >> a >> b >> s;
  if (abs(a) + abs(b) > s || s - (abs(a) + abs(b)) % 2 == 1)
    cout << "No";
  else
    cout << "YES";
  return 0;
}
