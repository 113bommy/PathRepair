#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, c = 0;
  string a, b, sub;
  cin >> a >> b;
  l = a.size();
  k = a.find(b);
  if (k == -1)
    c = 0;
  else
    c++;
  while ((k >= 0) && (k != l)) {
    k = a.find(b, k + 1);
    if ((k > 0) && (k <= l)) {
      c++;
    }
  }
  cout << c << '\n';
  return 0;
}
