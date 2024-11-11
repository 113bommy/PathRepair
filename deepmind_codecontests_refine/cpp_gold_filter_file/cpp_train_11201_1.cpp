#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int x, y, n, ind = 0, p = 1e5;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    if (x != y) {
      cout << "rated" << endl;
      return 0;
    }
    if (p < x) ind = 1;
    p = x;
  }
  if (ind) {
    cout << "unrated" << endl;
  } else {
    cout << "maybe" << endl;
  }
  return 0;
}
