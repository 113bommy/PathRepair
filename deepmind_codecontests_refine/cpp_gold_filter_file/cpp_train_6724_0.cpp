#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b, t, x, c = 0;
  cin >> n >> a >> b >> t;
  for (int i = 0; i < t; i++) {
    cin >> x;
    if (x > a && x < b) {
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
