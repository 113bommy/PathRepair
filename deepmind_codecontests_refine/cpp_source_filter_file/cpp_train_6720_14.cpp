#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c = 0, m = 0;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (a > b)
      c++;
    else if (a < b)
      m++;
  }
  if (m > c)
    cout << "Mishka";
  else if (m < c)
    cout << "Chris";
  else
    cout << "Friendship is magic!^^";
}
