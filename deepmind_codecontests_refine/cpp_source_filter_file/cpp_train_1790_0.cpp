#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main() {
  int n;
  int q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> q;
    if (q == 2)
      cout << 2 << endl;
    else if (q == 3)
      cout << 0 << endl;
    else
      cout << q % 2 << endl;
  }
}
