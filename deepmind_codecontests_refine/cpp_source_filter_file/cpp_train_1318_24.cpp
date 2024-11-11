#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const double pi = acos(-1);
int main() {
  string second;
  cin >> second;
  int c0 = 0, c1 = 0;
  for (int i = 0; i < second.size(); i++) {
    if (second[i] == 'o')
      c0++;
    else
      c1++;
  }
  if ((c0 > 0) && (c1 % c0 == 0))
    puts("YES");
  else
    puts("NO");
  return 0;
}
