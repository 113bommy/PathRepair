#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int f = count(str.begin(), str.end(), '4');
  int s = count(str.begin(), str.end(), '7');
  if (f == 0 && s == 0) cout << -1 << endl;
  if (f >= s)
    cout << 4 << endl;
  else
    cout << 7 << endl;
  return 0;
}
