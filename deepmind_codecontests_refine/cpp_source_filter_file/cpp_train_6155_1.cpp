#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, x, y;
  cin >> n;
  cin >> x >> y;
  if ((max(x, y) - 1) <= (n - min(x, y))) {
    cout << "White" << endl;
  } else {
    cout << "Black" << endl;
  }
}
