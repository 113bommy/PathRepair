#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, join;
  cin >> a;
  join = a;
  reverse(join.begin(), join.end());
  cout << a << join << endl;
}
