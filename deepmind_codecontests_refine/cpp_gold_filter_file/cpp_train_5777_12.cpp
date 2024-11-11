#include <bits/stdc++.h>
using namespace std;
int main() {
  string res = "1 2 4 3", cat;
  int n, i;
  cin >> n;
  if (n < 3) return cout << 1 << endl << 1, 0;
  if (n == 3) return cout << 2 << endl << "1 3", 0;
  cout << n << endl;
  for (i = n; i > 5; i--)
    if (!(i % 2)) cout << i << " ";
  cout << "2 4 1 3";
  for (i = n; i > 4; i--)
    if (i % 2) cout << " " << i;
  return 0;
}
