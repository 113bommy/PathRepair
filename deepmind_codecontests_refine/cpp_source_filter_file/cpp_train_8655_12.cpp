#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = (s.begin(), s.end(), 'a');
  cout << min(2 * a - 1, (int)s.length());
}
