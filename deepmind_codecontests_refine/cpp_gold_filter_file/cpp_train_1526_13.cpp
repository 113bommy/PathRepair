#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> a >> b;
  if (a > b) swap(a, b);
  a--;
  b--;
  a += n;
  b += n;
  int r = 0;
  while (a < b) {
    r++;
    a /= 2;
    b /= 2;
    if (a == 1) {
      cout << "Final!\n";
      return 0;
    }
  }
  cout << r << "\n";
  return 0;
}
