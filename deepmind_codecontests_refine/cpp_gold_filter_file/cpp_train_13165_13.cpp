#include <bits/stdc++.h>
using namespace std;
int d[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
int main() {
  string s;
  cin >> s;
  cout << d[s[0] - '0'] * d[s[1] - '0'] << endl;
  return 0;
}
