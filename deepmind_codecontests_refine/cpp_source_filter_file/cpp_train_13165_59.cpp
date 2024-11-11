#include <bits/stdc++.h>
using namespace std;
string str;
int from[10] = {7, 6, 2, 3, 3, 4, 2, 5, 1, 2};
int main() {
  getline(cin, str);
  cout << (from[str[0] - '0'] * from[str[1] - '0']) << endl;
  return 0;
}
