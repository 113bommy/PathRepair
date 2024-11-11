#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 0, c = 0, sm, sc;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m >> c;
    if (sm > sc) {
      m += 1;
    }
    if (sc > sm) {
      c += 1;
    }
  }
  if (m > c) {
    cout << "Mishka";
    return 0;
  }
  if (m < c) {
    cout << "Chris";
    return 0;
  }
  cout << "Friendship is magic!^^";
  return 0;
}
