#include <bits/stdc++.h>
using namespace std;
int v[12] = {2, 7, 2, 3, 3, 4, 3, 5, 1, 2};
int main() {
  char s[5];
  cin >> s;
  int a = (int)(s[0] - '0');
  int b = (int)(s[1] - '0');
  cout << v[a] * v[b] << endl;
  return 0;
}
