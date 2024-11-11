#include <bits/stdc++.h>
using namespace std;
int a[10] = {2, 6, 3, 3, 4, 3, 2, 5, 1, 2};
int main() {
  string s;
  cin >> s;
  cout << a[s[0] - '0'] * a[s[1] - '0'] << endl;
  return 0;
}
