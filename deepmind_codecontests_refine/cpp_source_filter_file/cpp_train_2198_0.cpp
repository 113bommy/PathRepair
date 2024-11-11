#include <bits/stdc++.h>
using namespace std;
using namespace std;
int a[100009], b[100009];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    cout << (1 << __builtin_popcount(a));
  }
  return 0;
}
