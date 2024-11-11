#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, m, c, nm, nc;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> m >> c;
    if (m > c) ++nm;
    if (c > m) ++nc;
  }
  if (nc > nm)
    cout << "Chris";
  else if (nc < nm)
    cout << "Mishka";
  else
    cout << "Friendship is magic!^^";
}
